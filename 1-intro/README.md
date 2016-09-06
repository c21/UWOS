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

#### Default terminal sucks ...
For Linux, you may find default purple terminal is neither looking pretty nor user-friendly. I admit, and I use another terminal emulator called tilda when I work in Linux. To get tilda in Linux:

```shell
$ sudo apt-get install tilda
```
apt-get is the command to manage software including install, uninstall, etc. Here we install a software package called tilda. You can explore a comprehensive explanation of apt-get by:

```shell
$ man apt-get
```
man command is to show the official manual of certain command, or you can use google to explore how to use a command.

For Mac OS X, personally I think the default terminal is good. You can customize terminal by clicking *preferences* option.

### ssh
ssh is a command to login to remote computer from your local computer. After login, you can run any command in shell, while the command is actually executed on that remote computer. Essentially, you work remotely on another computer.

Why it helps? In this course, we require you to write projects which can be run on CS lab's computer. Something developed on your own machine may not run successfully on CS lab's machine. With ssh, you can write projects on your laptop at your favourite place (maybe CS lab?), and don't need to go to a crowded CS lab.

To login to a remote computer, you should give your username and that computer's host name. Here **chengsu** is my username, and **royal-01.cs.wisc.edu** is one lab computer's name. Type in shell:

```shell
$ ssh chengsu@royal-01.cs.wisc.edu
chengsu@royal-01.cs.wisc.edu's password: 
```
You will be asked to provide password. You don't need to login to the same computer as I did. The list of available computer can be found [here](https://csl.cs.wisc.edu/services/instructional-facilities).

After type in your password, you will be placed in another shell at that remote computer. You shell should look like this:

```shell
Welcome to Ubuntu 14.04.5 LTS (GNU/Linux 3.13.0-95-generic x86_64)
===============================================================================
      REMINDER: BRING FOOD AND DRINK TO THE CS INSTRUCTIONAL COMPUTER LABS
===============================================================================
[chengsu@royal-01] (1)$ 
```

Note that before the prompt **$**, there should be **[your-cs-username@lab-machine-name]**. You can explore the current directory by:

```shell
[chengsu@royal-01] (1)$ ls
```

To logout lab's machine, just logout:
```shell
[chengsu@royal-01] (1)$ logout
```
Yes, logout is a command.

#### No hassle of password
One bad thing about ssh is you have to provide password when you want to login. One good thing is you can preset password once, and don't need to type in every time.

How to do that? One solution is to use public and private key. I encourage you to work through [this article](https://www.digitalocean.com/community/tutorials/how-to-use-ssh-to-connect-to-a-remote-server-in-ubuntu).

*Please read that article before scrolling down.*

After setting up the keys, you may find you cannot ssh in lab's machine without password. It's not the fault of ssh keys. At [our lab's website](https://csl.cs.wisc.edu/services/remote-access-csl-computers), it says:
*Linux workstations and servers: use ssh. Due to limitation of AFS, you can not use SSH Public Key authentication.*

Well, well. What is AFS? How it limits us? We will learn AFS later in our lecture. For now, let's quickly come up with some solution.

First, we will use **sshpass** instead of **ssh**. To install sshpass, here is the [instruction](https://gist.github.com/arunoda/7790979). After installing successfully, you can type in sshpass to explore how to use it:
```shell
$ sshpass
Usage: sshpass [-f|-d|-p|-e] [-hV] command parameters
   -f filename   Take password to use from file
   -d number     Use number as file descriptor for getting password
   -p password   Provide password as argument (security unwise)
   -e            Password is passed as env-var "SSHPASS"
   With no parameters - password will be taken from stdin

   -h            Show help (this screen)
   -V            Print version information
At most one of -f, -d, -p or -e should be used
```

First I create a file with content being my password. E.g., if my password is 123456, I create a file called my_password in my home directory:

```shell
$ cd ~
$ echo 123456 >my_password
```
**cd** is the command to change directory. The symbol **~** represents home directory. **echo** is command to display a text. Here we use I/O redirection（>）to display *123456* to file instead of standard output.

To login to lab's computer, one example is:
```shell
$ sshpass -f ~/my_password ssh chengsu@royal-01.cs.wisc.edu
```

It works!

Now you don't need to type in password anymore. But hold on one minute, let's keep your password secretly:
```shell
$ chmod 600 ~/my_password
```

**chmod** is the command to change file's mode(who can read, write and execute). In this way, this file can only be read and written by yourself.

One step further, though we don't need to type in password every time, but we have to type the verbose command every time:
```shell
$ sshpass -f ~/my_password ssh chengsu@royal-01.cs.wisc.edu
$ sshpass -f ~/my_password ssh chengsu@royal-01.cs.wisc.edu
$ sshpass -f ~/my_password ssh chengsu@royal-01.cs.wisc.edu
$ zzzzzz ...
```
It would be nice if we could have alias of our long command. We can! There is a command called alias:
```shell
$ alias wisc='sshpass -f ~/my_password ssh chengsu@royal-01.cs.wisc.edu'
$ wisc
```
Here I make an alias called **wisc** for our long command. Next time, when I type **wisc**, it will just run our previous command.

Everything looks good right now. However, if we close this terminal, and open again, **wisc** magic doesn't happen. So we need find some place to persist our command:
```shell
$ alias wisc='sshpass -f ~/my_password ssh chengsu@royal-01.cs.wisc.edu'
```

The place to store our command should be shell's dot file. If you have worked through [the article I recommended](matt.might.net/articles/settling-into-unix), you should know what I mean. Add the command to your shell's dot file. It would be either **.bash_profile** or **.bashrc**. In my case, it is **.bashrc**:
```shell
$ echo "alias wisc='sshpass -f ~/my_password ssh chengsu@royal-01.cs.wisc.edu'" >>~/.bashrc
$ source ~/.bashrc
```

We are done! **source** command is run the file in current shell. If you wonder the relationship between shell's dot file and shell, a short answer is when you set up a shell, it will run the commands in its dot file first. So the alias command gets a chance to run before we issue any command, and our life becomes easy.

**NOTE: In general, we should use ssh keys, which is safer than our sshpass trick.** 

#### Run the game for you (as promised)
As we said before, in shell you can play games. After sshing into lab's computer, you can find some games by:
```shell
$ ssh chengsu@royal-01.cs.wisc.edu
$ cd /usr/games
$ ls
```
In Linux, there are always some old games in above directory. However, we cannot run these games by basic ssh. By default, basic ssh cannot run any GUI application. However, we can use **X** option:
```shell
$ ssh -X chengsu@royal-01.cs.wisc.edu
$ cd /usr/games
$ ls
$ ./gnome-sudoku
```
If you want to learn more about **ssh**, you can use **man** command, or just read [this article](https://www.digitalocean.com/community/tutorials/how-to-use-ssh-to-connect-to-a-remote-server-in-ubuntu) I recommended.

Enjoy your sudoku!
