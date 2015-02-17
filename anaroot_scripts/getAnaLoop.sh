#!/bin/bash

if [ -z $1 ]
then
echo "Usage: getAnaLoop.sh [example analoop]"
echo "Example: getAnaLoop.sh TAlRawDataExample"
echo "select example which you want to modify:"
ls $TARTSYS/sources/AnaLoop/src/ | grep TAl | grep Example | grep -v TAlEnc | sed s/\.cc//g | sed s/\.o//g | sort | uniq
exit 0
fi

outcc=`echo $1 | sed s/Example//g`.cc
outhh=`echo $1 | sed s/Example//g`.hh

echo "cp $1.cc $outcc"
cp $TARTSYS/sources/AnaLoop/src/$1.cc $outcc
echo "cp $1.hh $outhh"
cp $TARTSYS/sources/AnaLoop/include/$1.hh $outhh

for ff in $outcc $outhh
do
sed s/EXAMPLE//g $ff | sed s/Example//g > /tmp/$ff
mv /tmp/$ff .
done

