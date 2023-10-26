#!/bin/sh

ab="addr.txt"

touch "$ab"

while [ true ]
do 
echo "MENUE"
echo "1) create"
echo "2) view"
echo "3. Insert a Record"
echo "4. Delete a Record"
echo "5. Modify a record"
echo "6. Exit"

echo "Enter your choice"
read choice

case $choice in 
1) 
    echo "Enter file name"
    read ab
    touch $ab

;;
2) 
    cat $ab
;;
3)
	echo "Enter the name of the person : "
	read personName
	echo "Enter the address : "
	read addr
	
	echo "$personName $addr" >> "$ab"
	
;;

4)
	echo "Enter the name of the person for deleting the record : "
	read personName
	
    sed -i "/$personName/d" "$ab"
		
		echo "successfully deleted!"
		cat "$ab"
		;;
		
		5)
		echo "Enter the name of the person whose record is to be modified : "
		read personName
		
		echo "Enter the new address : "
		read newAddr
		
		sed -i "/$personName/c\ $newAddr" "$ab"
		;;
		
		6)
		break
		;;
		
		*)
		echo "Invalid input"
		;;

esac

done
