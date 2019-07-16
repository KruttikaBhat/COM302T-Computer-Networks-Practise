set ns [new Simulator]

$ns color 1 Blue

set f [open out.tr w]
$ns trace-all $f
set nf [open out.nam w]
$ns namtrace-all $nf


#nodes
set n0 [$ns node]
set n1 [$ns node]

#links
$ns duplex-link $n0 $n1 5Mb 2ms DropTail
#$ns duplex-link-op $n0 $n1 orient right

$ns at 0.0 "$n0 label \" sender \" "
$ns at 0.0 "$n1 label \"receiver\" "

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
$tcp set fid_ 1
$tcp set window_ 1
$tcp set maxcwnd_ 1
$ns add-agent-trace $tcp tcp
$ns monitor-agent-trace $tcp
set tcpsink [new Agent/TCPSink]
$ns attach-agent $n1 $tcpsink

$ns connect $tcp $tcpsink
set ftp [new Application/FTP]
$ftp attach-agent $tcp

$ns at 0.5 "$ftp start"
$ns at 3.0 "$ns detach-agent $n0 $tcp ; $ns detach-agent $n1 $tcpsink "
$ns at 1.0 "$ns trace-annotate \"send packet 1\""
$ns at 1.4 "$ns trace-annotate \"recieve ack 1\""
$ns at 2.0 "$ns trace-annotate \"send packet 2\""
$ns at 2.5 "$ns trace-annotate \"receive ack 2\""
$ns at 3.2 "$ns trace-annotate \"send packet 3\""
$ns at 3.5 "$ns trace-annotate \"receive ack 3\""
$ns at 3.8 "$ns trace-annotate \"send packet 4\""
$ns at 4.0 "finish"

proc finish {} {
global ns f nf
$ns flush-trace
close $nf
exec nam out.nam &
exit 0
}

$ns run
