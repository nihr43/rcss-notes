##Sample Interview Questions




###Basic Linux
1. Who is logged into the system?
2. How much disk space is available and how much of your quota have you used?
3. Describe the difference between a primary group and group membership.
4. Create a "lab" folder where users can share data and use the proper (Posix ACL, NSFv4 ACL/sticky bits).




###Using a cluster
1. Create a SLURM jobfile and submit a test job to the cluster. Demonstrate the use of a Job Array.
2. Use the SLURM accounting to determine the resources consumed by a job.
3. Describe the difference between, and merits of, interactive and batch jobs.
4. When would using local scratch be optimal?
5. Tell us some metrics about how the cluster is used.





###Code Development Management
1. Create a git repository and push it to github or other location.
2. Create a branch and make some changes, show the difference.
3. Describe and demonstrate Test Driven Development (TDD)
4. Demonstrate the use of a class (in any language)




###Scientific Computation
1. Using scientific software (Julia and R) in interactive mode.
2. Provide a simple test code and execute as a job on the cluster (Julia, R, Python, etc.)
3. Demonstrate the use of parallelization.
4. Conduct a simple experimental analyses to demonstrate workflow management.




###Data Management
1. Create a simple SQLite3 database from a CSV file and perform a simple query. Use of C and scripting libraries acceptable but not direct examples.
2. What happens when you dump 10,000 files in a folder? How can you mitigate this problem.
3. Utilize an external service that has a REST API (S3, iPlant etc.).




###Access and Account Management
1. Create a group named rcss.
2. Create a user and add that user to the group rcss.
3. Query the ldap server for a specific user.




###Storage Management
1. Determine how much space is available on the current hardware's disk(s).
2. Identify, partition, and format out the new disk as xfs filesystem.
3. mount the disk under a new mount /scratch
4. make the mount accessible to the cluster.
5. reboot the cluster and validate /scratch is present on all nodes.
6. Grow an LVM partition on a live system.




###Network and Services
1. What is your IP?
2. What is your Gateway?
3. What are your DNS servers?
4. Provide the IP address for rhn.missouri.edu
5. Install a webserver.
6. Set httpd to start at boot.
7. What ports are listening?
8. What is the state of the local firewall?
9. Add httpd services to the firewall.
10. Give the compute node access to the Internet (NAT))
