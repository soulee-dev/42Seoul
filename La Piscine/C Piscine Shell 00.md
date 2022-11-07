# C Piscine Shell 00

soulee, 22, 08, 23

## Boiler Plate
```
#!/bin/sh
```
It's called shebang!

## Exercise 00
```
vi z
```

## Exercise 01

```
vi testShell00
```

## Excercise 02
```
touch -a -m -t 202206012342
```

```
touch -h -t 
```

-h will affect on each symbolic link instead of any referenced file  
-t change the specificed time  
-a change only the access time  
-m change only the modified time

## [Edited] Excercise 04
```
ls -Utmp
```

-m fill width with a comma seperated list of entries  
-p append / indicator to directories  
-U sort by creation time, newest first

## Excercise 05
```
git log --format='%H' -n 5
```
```git log``` load log from commited data 
-n number of lines  
--format pretty print the contents of the commit  
%# means commit hash

## Excercise 06p
```
git ls-files --others --ignored --exclude-standard 
```

ls-files show information about files in the index and the working tree

```--others``` means that show other files i.e(untracked)
```--ignored``` prints ignored files
```--exclude-standard``` Add standard git exclusions


## Excercise 07
```
patch -p < sw.diff
patch a sw.diff -o b
```
patch means apply the changed into specific file

## [Edited] Excercise 08
```
find . -type f \( -name "*~" -o -name "#*#" \) -delete -print
```

-o means or  
-exec means excute command  
\\; means end of exec  
{} means output of find  
\\( and \\) beacuase of shell treats those character as special, we need to use escaped character

## Excercise 09
```
0 search/42 42 42 file
```