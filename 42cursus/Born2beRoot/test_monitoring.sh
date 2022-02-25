# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_monitoring.sh                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 11:21:36 by hannkim           #+#    #+#              #
#    Updated: 2022/02/25 11:21:40 by hannkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# 1. The architecture of your operatins system and its kernel version
echo -n " #Architecture: "
uname -a

# 2. The number of physical processors.
echo -n " #CPU physical: "
cat /proc/cpuinfo | grep "physical id" | sort -u | wc -l

# 3. The number of virtual processors
echo -n " #vCPU: "
cat /proc/cpuinfo | grep -c "processor"

# 4. The current available RAM on your server and its utilization rate as a percentage
echo -n " #Memory Usage: "
free -m | grep Mem | awk '{printf "%d/%dMB (%.2f%%)\n", $3, $2, $3 / $2 * 100}'

# 5. The current available memory on your server and its utilization rate as a percentage
echo -n " #Disk Usage: "
df -BM | grep /dev/mapper/ | awk '{sum += $3} END {print sum}' | tr -d '\n'
echo -n "/"
df -BM | grep /dev/mapper/ | awk '{sum += $2} END {print sum}' | tr -d '\n'
echo -n "MB ("
df -BM | grep /dev/mapper/ | awk '{sum1 += $3 ; sum2 += $2} END {print sum1 / sum2 * 100}' | tr -d '\n'
echo "%)"

# 6. The current utilization rate of your processors as a percentage
echo -n " #CPU load: "
mpstat | grep all | awk '{print 100 - $13}' | tr -d '\n'
echo "%"

# 7. The date and time of the last reboot
echo -n " #Last boot: "
who -b | awk '{printf "%s %s\n", $3, $4}'

# 8. Whether LVM is active or not
echo -n " #LVM use: "
if [ "$(lsblk | grep lvm | wc -l)" -gt 0 ]; then
	echo "yes"
else
	echo "no"
fi

# 9. The number of active connections
echo -n " #Connections TCP : "
ss | grep -i tcp | wc -l | tr -d '\n'					# grep -i : ignore-case
echo " ESTABLISHED"

# 10. The number of users using the server
echo -n " #User log: "
who | wc -l

# 11. The IPv4 address of your server and its MAC address
echo -n " #Network: IP "
/sbin/ifconfig | grep broadcast | awk '{print $2}' | tr -d '\n'		# IPv4 address
echo -n " ("
/sbin/ifconfig | grep 'ether ' | awk '{print $2}' | tr -d '\n'		# MAC address
echo ")"

# 12. The number of commands executed with the sudo program
echo -n " #Sudo: "
cat /var/log/auth.log | grep --text sudo: | grep COMMAND= | wc -l | tr -d '\n'
