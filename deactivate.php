<?php
  
    // Connect to database 
      include 'config.php';
    // Check if userCode is set or not, if true,
    // change status else simply go back to the page
    if (isset($_GET['userCode'])){
  
        // Store the value from get to 
        // a local variable userCode
        $userCode=$_GET['userCode'];
  
        // SQL query that sets the status to
        // Deactivated to indicate deactivation.
        $sql="UPDATE `pupilsdetails` SET 
            `status`='Deactivated' WHERE userCode='$userCode'";
  
        // Execute the query
        mysqli_query($conn,$sql);
    }
  
    // Go back to registeredPupil.php
    header('location: registeredPupil.php');
?>