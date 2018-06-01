# Desserts

## Viewing Files in the Terminal

I often get tired of reading files like this:

```
$ open FILENAME
```

You end up with more open tabs than a bar full of drunk waiters!

There are many ways to view the contents of a file from the terminal itself. Here are some of them:

Using `cat` will print the entire contents of a file to the terminal.

```
$ cat FILENAME
```

Using `head` and `tail` will print the first 10 lines and the last 10 lines of a file respectively.

```
$ head FILENAME
$ tail FILENAME
```

You can print more or less than 10 lines by using the -n option, like so:

```
$ head -n 3 FILENAME
```

For my entree and dessert recipes, the first three lines contain the recipe title. The last three lines contain my personal notes about the recipe, if there are any.

By the way, I always keep five recipes in each directory at any time. If there are any missing, they might be lost in the `/entrees` directory.

--
Chef Gordon RAMsay
