<?php
if(isset($_POST['sub']))
{
$txt1=$_POST['n1'];
$txt2=$_POST['n2'];
$oprnd=$_POST['sub'];
if($oprnd=="+")
$res=$txt1+$txt2;
else if($oprnd=="-")
$res=$txt1-$txt2;
else if($oprnd=="*")
$res=$txt1*$txt2;
else if($oprnd=="/")
$res=$txt1/$txt2;
}
?>
<html>
<form method="post" action="">
calculator
<br>
no1:<input name="n1" value="<?php echo $txt1;?>">
<br>
no2:<input name="n2" value="<?php echo $txt2;?>">
<br>
res:<input name="res" value="<?php echo $res;?>">
<br>
<input type="submit" name="sub" value="+">
<input type="submit" name="sub" value="-">
<input type="submit" name="sub" value="*">
<input type="submit" name="sub" value="/">
</form>
</html>
