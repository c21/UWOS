# Introduction to C and Unix (09/07/2016)
Slides for discussion is [here](https://github.com/c21/UWOS/blob/master/1-intro/slides/slides.pdf), and code for demo is [here](https://github.com/c21/UWOS/tree/master/1-intro/demo). This page is to talk something we don't have time to cover in discussion.  

## Welcome to C
C is an old programming language which was born during 1970s! It's old though, but it's still powerful.

If you never learn programming, C is a good choice as your first language. You can read [this book](https://learncodethehardway.org/c) and [this tutorial](http://www.learn-c.org) to learn C.

If you have learned programming (mostly Java, I guess?), but never touch C and C++, you can read the [K&R C book](https://www.amazon.com/Programming-Language-Brian-W-Kernighan/dp/0131103628) to learn C.

If you have learned C (mostly in CS354, I guess?), well, welcome on board! You should definitely pay more attention to the usage and design of operating system(that's the whole point of this course, right?). But, in case you never read the [K&R C book](https://www.amazon.com/Programming-Language-Brian-W-Kernighan/dp/0131103628), I definitely encourage you to read it. It's a good book for experienced programmer.

If you are a programming geek (mostly major in CS, I guess?), and interested in everything (history, gossip, funny bug, mysterious feature) about C, you can have a look of [Expert C Programming book](https://www.amazon.com/Expert-Programming-Peter-van-Linden/dp/0131774298). E.g., why **gcc my.c -lm** works, but **gcc -lm my.c** doesn't work (... well, this bizarre problem only occurred in [old gcc](http://stackoverflow.com/questions/11336477/gcc-will-not-properly-include-math-h))?

## Welcome to Unix
Unix is an old operating system which was born with C. It's old though, but it's still powerful. It has many children (Linux, Mac OS X, BSD), and some children are twins (Linux: Ubuntu, CentOS, Debian, Fedora). If you want to know Unix's history, the chapter 2 of [The Book Which Helps You Fall Asleep](https://www.amazon.com/Advanced-Programming-UNIX-Environment-3rd/dp/0321637739) (... just kidding, it's a good reference book indeed!) is a good starting point. 

### Shell
Shell is a program running upon Unix operating system. Well, why we need to introduce it first, because in this course, we need to use this program all the time. E.g., with shell, we login lab's machine, write projects, test projects, submit projects, view grades, and play games (that's true, talk it later). In the old days of Unix without graphical user interface, shell was the user interface.

Shell provides user a prompt. User types in command, and shell runs the command. It's a servant and it's the best one.

#### Open shell
Shell is called terminal in modern systems such as Linux and Mac OS X. To open a terminal in Linux, type **Ctrl+Alt+T**. To open a terminal in Mac OS X, type **Command+Space**, and search for ''terminal''. After opening shell, you should have something like this:

```shell
you@heaven:~$
```
#### Run commands
You can try some commands, e.g., type in **whoami**, **date** and **pwd** one by one:

```shell
you@heaven:~$ whoami
chengsu
you@heaven:~$ date
Mon Sep  5 17:54:19 CDT 2016
you@heaven:~$ pwd
/home/chengsu
```

Your output should be different from me, but that's fine as long as it prints something out. Your shell works! From now, I will skip the funny **you@heaven:~$**, and only show **$** for a prompt in following example.

#### Explore more
There are many commands for you to explore. You may think above commands are boring, and you are going well in a GUI world without shell. Well, tell me how to count the number of lines of C files in one directory called /home/dir? It at least a non-trival work for me with GUI. In shell, you can type:

```shell
$ find /home/dir -name '*.c' | xargs cat | wc -l
```
and your servant always finishes his task.

You may now wonder what the heck is going on with above command. Specifically, the one-liner runs four commands one by one (find, xargs, cat, wc). In addition, it also uses filename shorthand (*.c) and pipe (|). Filename shorthand and pipe are features of shell.

For the beginner of Unix and shell, [this article](http://matt.might.net/articles/basic-unix) is a good starting point. After reading that, you can also read [this article](http://matt.might.net/articles/settling-into-unix). If you want to learn Unix and shell in a systematic way, [The Unix Programming Environment](https://www.amazon.com/Unix-Programming-Environment-Prentice-Hall-Software/dp/013937681X) is a great book. Chapter 1 covers most of everyday used commands.