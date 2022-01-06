# pipex

42 Project - Make in c the UNIX pipe

This project is an introduction to a well known mechanism of the UNIX system called pipes

# Compiling
> Run ```make```

# Running
```./pipex <infile> <cmd 1> <cmd 2> <outfile>```

# Exemple

Command:

```./pipex infile "ls -l" "wc -l" outfile```

Result in "**outfile**":

```
➜  pipex $ cat outfile
       9
```
