#writes files unique to each node on the shared filesystem


import subprocess



host = subprocess.check_output("hostname", shell=True)

file = open(host, 'w')
file.close

