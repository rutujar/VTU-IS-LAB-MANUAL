<?php
$file='visit.txt';
$count=strval(file_get_contents($file));
file_put_contents($file,$count+1);
echo(" you are visiter number:".$count);
?>
