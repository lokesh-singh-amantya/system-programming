stack=() # bash arrays are separated by spaces
stack_itr=0

push(){
	stack+=("${1#<}")
}

pop(){
	unset 'stack[-1]'
}

display(){
	local IFS=":"
	echo "${stack[*]}"
}

while IFS= read -r line; do # works realiably with special chars
	prevdata=""
	for tag in $(echo "$line" | grep -oE '</?[^ >]+'); do 
		# ignoring spaces helps to avoid any additional attributes
		data=$(echo "$line" | grep -oP '(?<=>)[^<]+')

		if [[ "$tag" == "<?"* ]]; then				# PROLOG
			echo -e "\e[33mprolog\e[0m	: $line"
		elif [[ "$tag" == "<!"* ]]; then 			# COMMENT
			echo -e "\e[34mcomment\e[0m	: $line"
		elif [[ "$tag" == "</"* ]]; then			# CLOSING
			pop
		else							# OPENING
			push "$tag"
			#display
		fi

## Handling data sperately
		if [[ "$prevdata" != "$data" ]]; then 	# PUSH - DISP - POP data
			push "$data"
			prevdata="$data"
			display
			pop
		fi

		#display
	done


done < "$1" > XMLtextlogs.txt


