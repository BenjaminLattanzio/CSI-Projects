
<?php
session_start();
if ($_SESSION['check']=='1') {
	if($_SERVER['REQUEST_METHOD']=='GET'){
	echo '<h1>Add a Post!</h1>
<form action="newPost.php" method="post">
	<p>Title: <input type="title" name="title" size="20" maxlength="60"> </p>
	<p>Post: <input type="text" name="text" size="20" maxlength="2000"></p>
	<p><input type="submit" name="submit" value="Post"></p>
</form>';
	}
// Check if the form has been submitted:

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
	// Need two helper files:
	
	require("../safe/connection.php");
	require("login_functions1.php");
	//require ("login1.php");
	
	// Check the login:
	

	
	
		post($dbc);
		// Redirect:
		redirect_user1('index.php');
		mysqli_close($dbc); // Close the database connection.
	} 
		
	}else { // Unsuccessful!
		// Assign $data to $errors for login_page.inc.php:
		echo"Not logged in!";
} // End of the main submit conditional.
// Create the page:





function post($dbc) {
 $title=trim($_POST['title']);
  $body = trim($_POST['text']);
  $userid = ($_SESSION['user_id']);

$query = "Insert into posts( title, post_body, user_id, post_date)
		 Values (?,?,?,now());";
$stmt = $dbc->prepare($query);
$stmt->bind_param('sss',$title, $body, $userid  );  
$stmt -> execute();
$stmt -> store_result();
//echo"Affected Rows: " . mysqli_affected_rows($dbc);
}






?>