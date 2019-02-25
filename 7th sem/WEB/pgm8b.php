<?php
header ('Content-Type:text/plain');
$matrix1=array(array(1,2),array(4,5));
$matrix2=array(array(1,2),array(4,5));
echo "\n\n\n";
echo "The order of matrix A is: ".count($matrix1)."X".count($matrix1[0])."\n";
echo "\n";
echo "The order of matrix B is: ".count($matrix2)."X".count($matrix2[0]);
echo "\n";
$rowCount=count($matrix1);
$colCount=count($matrix1[0]);
$rowCount2=count($matrix2);
$colCount2=count($matrix2[0]);
echo "The input matrix A is: \n";
for($r=0;$r<$rowCount;$r++)
{
    for($c=0;$c<$colCount;$c++)
    {
        echo $matrix1[$r][$c]."\t";
    }
    echo "\n";
}
echo "The input matrix B is: \n";
for($r=0;$r<$rowCount;$r++)
{
    for($c=0;$c<$colCount;$c++)
    {
        echo $matrix2[$r][$c]."\t";
    }
    echo "\n";
}
echo "The output transpose of Matrix A is: \n";
for($r=0;$r<$rowCount;$r++)
{
    for($c=0;$c<$colCount;$c++)
    {
        echo $matrix1[$c][$r]."\t";
    }
    echo "\n";
}
echo "The result of addition of the two matrices is : \n";
for($r=0;$r<$rowCount;$r++)
{
    for($c=0;$c<$colCount;$c++)
    {
        $val=$matrix1[$r][$c]+$matrix2[$r][$c];
        echo $val."\t";
    }
    echo "\n";
}
echo "The result of multiplication of the two matrices is:\n";
if($colCount==$rowCount2)
{
    for($r=0;$r<$rowCount;$r++)
    {
        for($c=0;$c<$colCount2;$c++)
        {
            $res=0;
            for($k=0;$k<$colCount;$k++)
            {
                $res=$res+$matrix1[$r][$k]*$matrix2[$k][$c];
            }
        echo $res."\t";
        }
        echo "\n";
    }
}
else
{
echo "The matrix multiplication is not possible";
}
?>
