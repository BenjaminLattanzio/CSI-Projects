
<?php
session_start();
 # Script 12.8 - login.php #3
// This page processes the login form submission.
// The script now uses sessions.
// Check if the form has been submitted:
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
	// Need two helper files:
	require('login_functions1.php');
	//put lines below into a file require('../mysqli_connect.php');
	require("../safe/connection.php");
	
	// Check the login:
	list($check,$data) = check_login($dbc, $_POST['email'], $_POST['pass']);
	if ($check) { // OK!
		// Set the session data:
	
		$_SESSION['user_id'] = $data['user_id'];
		$_SESSION['nick_name'] = $data['nick_name'];
		$_SESSION['check'] = '1';
		
		echo"<h1>You have logged in!</h1>";
		
		//sleep(5);

		// Redirect:
		redirect_user1('index.php');
	} else { // Unsuccessful!
		// Assign $data to $errors for login_page.inc.php:
		$errors = $data;
		foreach($errors as $e)
		echo $e."<br/>";
		$_SESSION['check'] = '0';
		
	}
	mysqli_close($dbc); // Close the database connection.
} // End of the main submit conditional.
// Create the page:
echo '<h1>Login</h1>
<form action="login1.php" method="post">
	<p>Email Address: <input type="email" name="email" size="20" maxlength="60"> </p>
	<p>Password: <input type="password" name="pass" size="20" maxlength="20"></p>
	<p><input type="submit" name="submit" value="Login"></p>
</form>';



?>

