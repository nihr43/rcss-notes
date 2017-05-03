## LVM

LVM abstracts disks from the filesystem, providing features such as live volume resizing

### Components
	- Physical Volumes
	- Logical Volumes
	- Volume Groups

### Semantics
	- PGs are disks and belong to VGs
	- VGs are groups of physical volumes
	- LGs present volumes to the filesystem

### Formatting
	- initialize a disk as a physical volume using `pvcreate /dev/sdx`
	- create a volume group containing /dev/sdx; `vgcreate new_vg /dev/sdx`
	- create a logical volume using the new VG; `lvcreate new_lv new_vg`

### Other Commands
	- `lvs` list logical volumes
	- `vgs` list volume groups
	- `lvdisplay` show volume information
	- `vgextend` add additional physical volumes to an existing volume group
