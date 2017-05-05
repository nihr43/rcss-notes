#!/bin/bash

#creates 1000 files; compresses them; deletes the originals


for i in {1..1000}
do
	touch $i.file
done

tar --remove-files -czvf files.tar.gz *.file