#195. Tenth Line
#Example:

#Assume that file.txt has the following content:

#Line 1
#Line 2
#Line 3
#Line 4
#Line 5
#Line 6
#Line 7
#Line 8
#Line 9
#Line 10
#Your script should output the tenth line, which is:

#Line 10
#Note:
#1. If the file contains less than 10 lines, what should you output?
#2. There is at least three different solutions. Try to explore all possibilities.

#It is natural to consider head -10 file.txt | tail -1 as the candidate which cannot output the 10th line if the file has fewer than 10 lines. But it can be easily fixed as below.

tail -n+10 file.txt | head -1
#Alternatively, sed, awk, cut and mapfile can do the job as well (e.g. below)

sed -n '10p' file.txt
cut -f10 -d$'\n' file.txt
awk 'NR==10' file.txt
mapfile -s 9 -n 1 array < file.txt
echo "${array[0]}" | head -1
#Last but not least, the most flexible solution would be writing ones own script.

no=0                                                                  
while IFS= read -r line                                               
do                                                                        
    ((no=$no+1))
    if [[ $no -eq 10 ]]                                                   
    then                                                                      
        echo $line
		break
    fi                                                                
done < "file.txt"   