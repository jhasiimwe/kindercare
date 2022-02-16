<?php
  
    // Connect to database 
     include 'config.php';
    // Check if userCode is set
    if (isset($_GET['userCode'])){
  
        // Store the value from get to a 
        // local variable userCode
        $userCode=$_GET['userCode'];
  
        // SQL query that sets the status
        // to Activated to indicate activation.
        $sql="UPDATE `pupilsdetails` SET 
             `status`='Activated',`activationrequest`='' WHERE userCode='$userCode'";
  
        // Execute the query
        mysqli_query($conn,$sql);
    }
    
    // Go back to course-page.php
    header('location: registeredPupil.php');
   
?>