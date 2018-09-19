LockFile=/text.lock
while :
do
if ! [ -f ${LockFile} ]; then
echo 0 > LockFile
#touch ${LockFile}
echo $(($(tail -1 "text.txt") + 1)) >> text.txt
wait
rm -rf ${LockFile}
fi
done