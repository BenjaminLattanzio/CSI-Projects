<?php
//http://163.238.35.165/~lattanzio/newExpression.php
echo'
<form action="newExpression.php" method = "post">
Enter String to Search: <input type="text" size="50"  maxlength="48"name="subject"><br />
<input type="submit" name="submit">
</form>';



$subject = $_POST['subject'];
echo '<h1> You submitted : ' . $subject . '</h1>';
//$replacement = "-";
$pattern = '/[aeiouAEIOU]+/i';
if(preg_match($pattern,$subject))
$subject = preg_replace($pattern,'-',$subject);

echo '<h1> The output is : ' . $subject . '</h1>';
?>

