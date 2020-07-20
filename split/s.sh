for ((i = 1; ;++i)); do
	echo $i
	./gen $i > split.in
	./split 
	java split
	diff -w split1.out split2.out || break
done
