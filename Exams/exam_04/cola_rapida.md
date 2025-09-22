# Exam 04 – Cola rápida (para decorar)

Formato: mínimo pra relembrar na hora. Inclui includes, protótipos, esqueleto e passos mentais.

---

## 0) ft_popen
- Ideia: pipe + fork + dup2 + execvp
- Includes: <unistd.h>, <stdlib.h>

```c
int ft_popen(const char *file, char *const argv[], char type)
{
    if (!file || !argv || (type!='r' && type!='w')) return -1;
    int fd[2]; if (pipe(fd)==-1) return -1;
    if (fork()==0) { // filho
        if (type=='r') { dup2(fd[1], 1); close(fd[0]); }
        else { dup2(fd[0], 0); close(fd[1]); }
        close(fd[0]); close(fd[1]);
        execvp(file, argv); exit(-1);
    }
    if (type=='r') { close(fd[1]); return fd[0]; }
    else          { close(fd[0]); return fd[1]; }
}
```

Passos: validar → pipe → fork → no filho dup2/exec → no pai fecha e retorna fd certo.

---

## 0) picoshell
- Ideia: encadear cmds com pipes (cmd[i] | cmd[i+1])
- Includes: <unistd.h>, <stdlib.h>, <sys/wait.h>

```c
int picoshell(char **cmds[])
{
    if (!cmds||!cmds[0]) return 1;
    int prev=-1, p[2], st, rc=0;
    for (int i=0; cmds[i]; i++) {
        if (cmds[i+1] && pipe(p)) return 1;
        if (fork()==0) { // filho
            if (prev!=-1) { dup2(prev,0); close(prev); }
            if (cmds[i+1]) { close(p[0]); dup2(p[1],1); close(p[1]); }
            execvp(cmds[i][0], cmds[i]); exit(127);
        }
        if (prev!=-1) close(prev);
        if (cmds[i+1]) { close(p[1]); prev=p[0]; }
    }
    while (wait(&st)!=-1) if (WIFEXITED(st) && WEXITSTATUS(st)!=0) rc=1;
    return rc;
}
```

Passos: laço cmds → pipe se precisa → filho conecta dup2 → exec → pai fecha fds → wait todos.

---

## 0) sandbox
- Ideia: rodar função com timeout (alarm + signals + waitpid)
- Includes: <stdbool.h>, <unistd.h>, <sys/wait.h>, <signal.h>, <errno.h>, <stdio.h>, <string.h>

```c
static void noop(int s){(void)s;}
int sandbox(void (*f)(void), unsigned t, bool v)
{
    pid_t pid=fork(); if(pid==-1) return -1;
    if(pid==0){ alarm(t); f(); exit(0); }
    struct sigaction sa={0}; sa.sa_handler=noop; sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM,&sa,0); alarm(t);
    int st; pid_t r=waitpid(pid,&st,0); alarm(0);
    if(r==-1 && errno==EINTR){ kill(pid,SIGKILL); waitpid(pid,0,0); if(v) printf("Bad function: timed out after %u seconds\n",t); return 0; }
    if(WIFEXITED(st)){ int c=WEXITSTATUS(st); if(c==0){ if(v) puts("Nice function!"); return 1;} if(v) printf("Bad function: exited with code %d\n",c); return 0; }
    if(WIFSIGNALED(st)){ if(v){ if(WTERMSIG(st)==SIGALRM) printf("Bad function: timed out after %u seconds\n",t); else printf("Bad function: %s\n", strsignal(WTERMSIG(st))); } return 0; }
    return -1;
}
```

Passos: fork → filho alarm+f() → pai arma SIGALRM → waitpid → decide por exit/signal/timeout.

---

## 1) argo
- Ideia: parser simples (STRING, INTEGER, MAP)
- Includes: <stdio.h>, <ctype.h>, <string.h>, <stdlib.h>

Palavras-chave: peek, accept, expect, parse_string, parse_int, parse_map.

```c
typedef struct json{enum{MAP,INTEGER,STRING}t; union{struct{struct pair*data;size_t sz;}m;int i;char*s;};}json;
typedef struct pair{char*key;json val;}pair;
int peek(FILE*f){int c=getc(f); ungetc(c,f); return c;}
int accept(FILE*f,char c){ if(peek(f)==c){getc(f); return 1;} return 0; }
int expect(FILE*f,char c){ if(accept(f,c)) return 1; /* unexpected */ return 0; }
```

Esqueleto de cada parser:
```c
int parse_int(json*d, FILE*f){ int n; if(fscanf(f,"%d",&n)==1){ d->t=INTEGER; d->i=n; return 1;} return -1; }
int parse_string(json*d, FILE*f){ char buf[4096]; int i=0; if(!expect(f,'"')) return -1; int c; while((c=getc(f))!='"'){ if(c==EOF) return -1; if(c=='\\'){ c=getc(f); if(c==EOF) return -1; } buf[i++]=c; } buf[i]=0; d->t=STRING; d->s=strdup(buf); return 1; }
int parse_map(json*d, FILE*f){ pair*it=0; size_t n=0; if(!expect(f,'{')) return -1; while(!accept(f,'}')){ json k,v; if(parse_string(&k,f)==-1) return -1; if(!expect(f,':')) return -1; if(parser(&v,f)==-1) return -1; it=realloc(it,sizeof(*it)*(n+1)); it[n].key=k.s; it[n].val=v; n++; if(!accept(f,',') && peek(f)!='}') return -1; } d->t=MAP; d->m.data=(void*)it; d->m.sz=n; return 1; }
int parser(json*d, FILE*f){ int c=peek(f); if(c=='"') return parse_string(d,f); if(isdigit(c)||c=='-') return parse_int(d,f); if(c=='{') return parse_map(d,f); return -1; }
```

Passos: detectar tipo → delegar → montar MAP com realloc → serializar depois.

---

## 1) vbc
- Ideia: parser de expressão infixa com + e * (precedência e associatividade à esquerda)
- Includes: <stdio.h>, <ctype.h>, <stdlib.h>

Regras:
- expr := term { '+' term }
- term := factor { '*' factor }
- factor := DIGIT | '(' expr ')'

Snippets essenciais:
```c
int accept(char **s,char c){ if(**s==c){(*s)++; return 1;} return 0; }
int expect(char **s,char c){ if(accept(s,c)) return 1; /* unexpected */ return 0; }

node *parse_factor(char **s){ if(isdigit(**s)){ node n={VAL, **s-'0',0,0}; (*s)++; return new_node(n);} if(accept(s,'(')){ node*n=parse_expr(s); if(!expect(s,')')){ destroy_tree(n); return 0;} return n;} /* unexpected */ return 0; }
node *parse_term(char **s){ node*l=parse_factor(s); while(accept(s,'*')){ node*r=parse_factor(s); node n={MULTI,0,l,r}; l=new_node(n);} return l; }
node *parse_expr(char **s){ node*l=parse_term(s); while(accept(s,'+')){ node*r=parse_term(s); node n={ADD,0,l,r}; l=new_node(n);} return l; }
```

Passos: fator → termo → expressão; tratar parênteses; validar fim da string no main.
