## Sample Interview Questions




### Basic Linux
1. Who is logged into the system?
	- found using `users`
	- `cat /etc/passwd` to view all users
2. How much disk space is available and how much of your quota have you used?
	- `df` to show mountpoints and available space, `du` to show file sizes in directory
	- quotas-
3. Describe the difference between a primary group and group membership.
4. Create a "lab" folder where users can share data and use the proper (Posix ACL, NSFv4 ACL/sticky bits).




### Using a cluster
1. Create a SLURM jobfile and submit a test job to the cluster. Demonstrate the use of a Job Array.
2. Use the SLURM accounting to determine the resources consumed by a job.
3. Describe the difference between, and merits of, interactive and batch jobs.
4. When would using local scratch be optimal?
5. Tell us some metrics about how the cluster is used.





### Code Development Management
1. Create a git repository and push it to github or other location.
	- `git init` to create new repo
	- `git add` files to be tracked
	- `git commit -a` commit changes to repo
	- `git remote add origin 'address'` save remote location to be pushed to with name origin
	- `git push` push repo to remote
2. Create a branch and make some changes, show the difference.
3. Describe and demonstrate Test Driven Development (TDD)
4. Demonstrate the use of a class (in any language)




### Scientific Computation
1. Using scientific software (Julia and R) in interactive mode.
2. Provide a simple test code and execute as a job on the cluster (Julia, R, Python, etc.)
3. Demonstrate the use of parallelization.
4. Conduct a simple experimental analyses to demonstrate workflow management.




### Data Management
1. Create a simple SQLite3 database from a CSV file and perform a simple query. Use of C and scripting libraries acceptable but not direct examples.
2. What happens when you dump 10,000 files in a folder? How can you mitigate this problem.
	- Depending on the filesystem, 10,000 files in a single directory may be too many.  Problems of this nature could be mitigated by piping stdout into a tool like tar.
3. Utilize an external service that has a REST API (S3, iPlant etc.).




### Access and Account Management
1. Create a group named rcss.
	- `groupadd rcss`
2. Create a user and add that user to the group rcss.
	- `adduser user`
	- `usermod -aG rcss user`
3. Query the ldap server for a specific user.




### Storage Management
1. Determine how much space is available on the current hardware's disk(s).
	- `df -h`
2. Identify, partition, and format out the new disk as xfs filesystem.
	- `fdisk -l` to identity attached disks
	- 
3. mount the disk under a new mount /scratch
	- create directory `/scratch`, then run `mount -t xfs /dev/sdx1 /scratch`
	- make changes to `/etc/fstab` to mount at boot
4. make the mount accessible to the cluster.
	- edit `/etc/exports` to share via nfs
	- on nodes, mount and edit `/etc/fstab` with filesystem type `nfsv4`.  The addresses of, or a wildcard for the subnet where the nodes reside, needs to be specified in the nfs server's exports.
5. reboot the cluster and validate /scratch is present on all nodes.
	- the new mountpoints should be seen using `df`
6. Grow an LVM partition on a live system.




### Network and Services
1. What is your IP?
	- `ip addr` for all interfaces and their addresses
2. What is your Gateway?
	- if package `net-tools` is installed, `netstat-nr` shows known routes.  Address associated with '0.0.0.0' is the default route.
3. What are your DNS servers?
	- `cat /etc/resolv.conf`
4. Provide the IP address for rhn.missouri.edu
	- 128.206.14.43
	- can be found using `ping`, or `dig` if package `bind-utils` is available
5. Install a webserver.
	- `yum install httpd` for apache
6. Set httpd to start at boot.
	- command to manage services is `systemctl`
	- `systemctl status httpd` to view status of apache
	- `systemctl enable httpd` to start at boot
	- `systemctl start httpd` to start without rebooting
7. What ports are listening?
	- `nmap -sT localhost` for listening tcp ports on localhost
8. What is the state of the local firewall?
9. Add httpd services to the firewall.
10. Give the compute node access to the Internet (NAT))
