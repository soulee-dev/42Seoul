# C Piscine Shell 01

soulee, 22, 08, 22

## Boiler Plate
```
#!/bin/sh
```

## Exercise 00

## Exercise 01
```
id -G -n $FT_USER | tr ' ' ','
```

With tr command, replace blank into ','

-G option displays different group ids

-n option displays name of group id 


## Excerise 02
```
find . -type f -name '*.sh' -exec basename {} .sh \;
```

Find the type:file and ending with .sh in current folder, and execcte basename with sufficx .sh wich return filename without 

. means current folder

\* wildcard means everything filtered in

basename extracts filename from directory

{} is filled with array that returned from find

## Excercise 03

```
find . | wc -l
```

Print number of lines returned from find . (Recursively find all of directories, files cuz, there is no type-option)

'wc' command with -l option counts number of lines

## Excersie 04
```
ifconfig -a | awk '/ether /{print $2}'
```
awk split line by line, and space by space so when there is data

> aaaa ether aaa

```
$DATA | awk '/ether/'{print $1}
```
will return aaaa

## Exercise 05
Just contain quote, you can make file with special characters

## Excercise 06
```
ls -l | sed -n 'n;p'
```

Sed means Stream Editor, n menas add new-line pattern, p means print

By default, each line of input is echoed to the standard output
             after all of the commands have been applied to it.  The -n option
             suppresses this behavior. (Text matched with pattern)

## Excercise 07
```
cat /etc/passwd | grep -v '\#' | sed -n '1d;p' | cut -d ':' -f 1 | rev | sort -r | awk 'NR>=ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]' | xargs | sed 's/ /,/g' | sed 's/$/./'
```

``` grep -v '/#' ```
 grep print lines that match patterns that match regular expressions, and -v option will invert this setting, so it will remove all of comments in passwd

 and # is speical character so, it needs Escaped string

 ```sed -n '1d;p'``` delete first line, and print all

``` cut -d ':' -f 1``` split by : and, get first item line by line

```rev``` reverse string

```sort -r``` sort, but reversed one

```awk 'NR>=ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]'``` from line $FT_LINE1 to line $FT_LINE2

```xargs``` multiple line into single line with space

```sed 's / /,/g'``` s means subsitute, and g means globally

```sed 's/$/./'``` add . in end of line

```
export FT_LINE1=7
export FT_LINE2=15
```

## Excercise 08
```
#!/bin/bash
echo $FT_NBR1 + $FT_NBR2 | sed "s/\'/0/g" | sed 's/\\/1/g' | sed "s/\"/2/g" | sed 's/?/3/g'  | sed 's/!/4/g' | tr "mrdoc" "01234" | xargs echo "obase=13;ibase=5;" | bc | tr "0123456789ABC" "gtaio luSnemf"
```

Reference: Escape strings

```
' > 0
\ > 1
" > 2
? > 3
! > 4
```

obase (original base)
ibase ()

bc is basic calculator for

```
export FT_NBR1=\\\'\?\"\\\"\'\\
export FT_NBR2=rcrdmddd
export FT_NBR1=\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"
export FT_NBR2=dcrcmcmooododmrrrmorcmcrmo
```

## Excericse 09
```
offest find_string_at_42 is_eqaul_42 
0 search/42 42 42 file
```

[Reference](https://cweiske.de/tagebuch/custom-magic-db.htm)