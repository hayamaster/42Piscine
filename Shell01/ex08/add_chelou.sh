n1=$(echo $FT_NBR1 | tr "\'\\" "01" | tr '\"\?\!' '234')
n2=$(echo $FT_NBR2 | tr "mrdoc" "01234")
n3=$(echo "obase=13; ibase=5; $(echo $n1 + $n2)" | bc )
echo $n3 | tr "0123456789ABC" "gtaio luSnemf"
