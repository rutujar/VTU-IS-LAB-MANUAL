<html>
<head>
<script type="text/javascript">
function startTime()
{
var d=new Date();
var h=d.getHours();
var m=d.getMinutes();
var s=d.getSeconds();
document.getElementById("txt").innerHTML=h+":"+m+":"+s;
setTimeout('startTime()',1000);
}
</script>
<style type="text/css">
h1
{
font-size:70px;
}
</style>
</head>
<body bgcolor="#385" text="red" onload="startTime()">
<br>
<h1 align="center"> The time from the load system is <span id="txt"> </span>
</h1>
</body>
</html>
<?php
$today=date("H:I:S");
?>
<!DOCTYPE html>
<html>
<body>
<h1>
<center>
<?php echo "The time from the Server is " .date("h:i:sa");?>
</center>
</h1>
</body>
</html>
