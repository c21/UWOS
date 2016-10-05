# Dive into xv6

In our projects, we will spend a substantial part of time with xv6. xv6 is a small operating system used in our course project. For comprehensive introduction of this operating system, please refer to [this original tutorial](https://pdos.csail.mit.edu/6.828/2012/xv6/book-rev7.pdf). The tutorial gives very good explanation of xv6's implementation. If you want to understand how a system works, please read that tutorial.

## Get xv6 source code
We have xv6's source code in ~cs537-1/ta/xv6/. We create an archive called xv6.tar.gz. So let's get xv6 source code by decompress that archive and get familiar with one command tar.

```shell
$ tar -xf ~cs537-1/ta/xv6/xv6.tar.gz
```

If you run above command in your home directory after ssh, you can see new directory called xv6. That's the xv6:) Before entering xv6 directory, let's talk a little about tar. tar is an executable (so called utility) provided by GNU. It's used for file compression and decompression. Here we decompress the file **~cs537-1/ta/xv6/xv6.tar.gz** by passing options **x** and **f**. **x** means we want to do decompression, **f** means we want to decompress file **~cs537-1/ta/xv6/xv6.tar.gz**. You can learn more about tar by **tar --help**. Can you finish a task to compress a file by using tar?

## Basic structure of xv6
Enter xv6 directory that we create by tar, you can see following files and directories. 

```shell
$ cd xv6/
$ ls
FILES  include/  kernel/  Makefile  Makefile~  README  tools/  user/  version
```

You should pay most attention to 3 directories. **kernel** directory contains main implementation of xv6. **user** directory contains user application and library constructed on top of xv6. Interesting applications include shell (user/sh.c), grep (user/grep.c), ls (user/ls.c), etc. **include** directory contains important predefined constants and interface between kernel and user application.

## Search a keyword
When browsing xv6's source code, you may want to find a word (e.g. function name, variable name, etc). To search a keyword in one directory, you can use **grep**:

```shell
$ cd xv6/kernel/
$ grep -r 'struct proc'
```

**grep** with option **r** is to search a keywork in current directory recursively for each file. You can also grep on certain files by typing:

```shell
$ grep 'struct proc' proc.c sysproc.c
```

Here we don't need to give option **r**, and we search keyword 'struct proc' in proc.c and sysproc.c.

## Jump between code
When working in this project, sometimes you may want to find out where's a certain function defined, and where's a certain struct defined. You can always use **grep**, but **grep** just search for apperance of keyword, but doesn't know semantics of our xv6 code. When working in C project, a tool called **ctags** can be more helpful than **grep**:

```shell
$ cd xv6/
$ ctags -R */*
```

By typing **ctags -R \*/\***, we generate a **tags** file for our whole xv6 project. This **tags** file is used by **ctags** internally to help us jump around code.

Before the magic happens, let's do one more thing:

```shell
$ cd xv6/
$ echo 'set tags='`pwd`'/tags' >>~/.vimrc
```

This will help vim to work with ctags.

Then we open a file:

```shell
$ vim kernel/sysproc.c
```

Move cursor to the string **fork()** in line 12 of file. Then type **ctrl-]**. See? You should jump to the definition of fork() function! If you want to go back, type **ctrl-o**. Brove! You can use this method search for structure definition too. If you have multiple matchings by typing **ctrl-]**, type **:tn** to see next matching, type **:tp** to see previous matching, and type **:ts** to see all matchings.

