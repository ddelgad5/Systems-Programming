# Entrees

## Moving Files in the Terminal

Sometimes when I ask my assistants to take care of my files they get careless. In all likelihood they have put a recipe here that is meant to be in the `/desserts` directory.

To move files in the terminal, use the `mv` command:

```
$ mv FILE_SOURCE FILE_DESTINATION
```

Be careful with the file paths when moving files. For example, if you are in the `/entrees` directory, this command will not work:

```
$ mv entrees/RECIPE.txt desserts/RECIPE.txt
```

Try that command to see why. You may need to move up a folder. Remember how to do that?

If you get any errors when using `mv`, read them carefully. If you move a file somewhere unexpectedly, use `ls` and `cd` to find it.

Also, if your terminal is getting too cluttered with previous commands, you can get a fresh slate like this:

```
$ clear
```

--
Chef Gordon RAMsay
