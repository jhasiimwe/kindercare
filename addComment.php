
<?php
include 'config.php';
if(isset($_GET["add"])){
  $comment=$_GET['comment'];

   $userCode = $_GET['userCode'];
   $assignmentId = $_GET['assignmentId'];

    // SQL query that updates the score table by adding 
    // a comment to the comment column for a specific assignment by a specific pupil
    $sql="UPDATE `scores` SET 
          `comment`='$comment' WHERE userCode='$userCode' AND assignmentId ='$assignmentId'";

//     // Execute the query
     mysqli_query($conn,$sql);
    header('location:viewScores.php');
 
   }
