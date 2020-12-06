for ((i = 1; ; ++i)); do
	echo $i
	./gen $i > int
	tmp=$(./brute < int)
	if [[ tmp -ne 1061109567 ]] 
	then
		diff -w <(./hayfeast < int) <(./brute < int) || break
	fi
done
