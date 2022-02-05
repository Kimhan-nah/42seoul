##!/bin/bash


## 운영체제 및 커널 버전의 아키텍처
printf " #Architecture:  "
uname -srvmo
# -s : kernel name, -r : kernel release, -v : kernel version, -m : machine hardware name, -o : operating system OS

## 물리 프로세서 수 (CPU)
printf " #CPU physical: "
cat /proc/cpuinfo | grep "physical id" | sort -u | wc -l
# /proc/cpuinfo : cpu 코어에 대한 정보
# "physical id" : user당 사용할 수 있는 프로세스 최대 개수 
# sort -u : 정렬 후 중복행 제거
# cat /proc/cpuinfo | grep "physical id" | sort | uniq | wc -l
# nproc --all


## 가상 프로세서 수 (vCPU)
printf " #vCPU: "
cat /proc/cpuinfo | grep -c "processor"
# "processor" : 코어 id 정보


## 서버에서 현재 사용 가능한 RAM 및 사용률	?Memory Usage?
printf " #Memory Usage: "
free -m | grep Mem | awk '{printf "%d/%dMB (%.2f%%)\n", $3, $2, $3 / $2 * 100}'
# free, vmstat, top, /proc/meminfo


## 서버에서 현재 사용 가능한 메모리 및 사용률	?Disk Usage2?
printf " #Disk Usage: "
df -BM -a | grep /dev/mapper/ | awk '{sum+=$3}END{print sum}' | tr -d '\n'
printf "/"
df -BG -a | grep /dev/mapper/ | awk '{sum+=$4}END{print sum}' | tr -d '\n'
printf "Gb ()"
df -BM -a | grep /dev/mapper/ | awk '{sum1+=$3 ; sum2+=$4}END{printf "%d", sum1 / sum2 * 100}' | tr -d '\n'
printf "%%)\n"
 # df : Disk Free (디스크 여유 공간)
 # -BM : MByte 단위로 출력
 # -a : 자세하게 출력
 # sum += $n : 모든 레코드의 합
 # END{} : 모든 레코드 처리가 끝나고 프로그램이 종료될 때 실행


## 프로세서의 현재 사용률			?CPU load?
printf " #CPU load: "


## 마지막 재부팅 날짜 및 시간
printf " #Last boot: "


## LVM 활성 상태 확인
printf " #LVM use: "


## 활성 연결 수 				?Connections TCP?
printf " #Connections TCP: "


## 서버를 사용하는 사용자 수			?User Log?
printf " #User log: "


## 서버의 IPv4 주소와 MAC 주소			?Network?
printf " #Network: IP "


## sudo 프로그램으로 실행된 명령 수		?Sudo?
printf " #Sudo : "
