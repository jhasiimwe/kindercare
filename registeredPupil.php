<!DOCTYPE html>
<?php
session_start();
if(!isset($_SESSION["staffId"])){
    header('location:login.php');
}
?>

<?php 
echo "
        <script>
        function myPupilRegFunction() {
        location.href = 'http://localhost/KINDERCARE/registeredPupil.php';
        }
        </script>
        ";
if (isset($_POST['register'])) {
    ob_start();
    include "config.php"; 
  // receive all input values from the form
  $fname = mysqli_real_escape_string($conn, $_POST['fname']);
  $lname = mysqli_real_escape_string($conn, $_POST['lname']);
  $pnumber = mysqli_real_escape_string($conn, $_POST['pnumber']);
  $usercode = mysqli_real_escape_string($conn, $_POST['usercode']);

  $errors = array();
  
  $register_query = "SELECT * FROM pupilsdetails WHERE  userCode='$usercode' LIMIT 1";
  $result = mysqli_query($conn, $register_query);
  $pupil = mysqli_fetch_assoc($result);
  
  if ($pupil) { 
    if ($pupil['userCode'] === $usercode) {
        echo "pupil code already exists";
      }
  }
  if (count($errors) === 0) {
  	$query = "INSERT INTO pupilsdetails (firstName, lastName, phoneNumber, userCode) VALUES('$fname', '$lname','$pnumber', '$usercode')";
      mysqli_query($conn, $query);
        // header('location:registeredPupil.php');
}
}
?>

<html lang="en">
<head>
<style>
    /* table,td,th {
        border: 1px solid black;
    } */
    tr:nth-child(even) {
        background-color: Lightblue;
    }
</style>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta name="description" content="">
    <meta name="author" content="">
     <link rel = "shortcut icon" href = "img/logo2.png">
    <title>KINDERCARE</title>

    <!-- Custom fonts for this template-->
    <link href="vendor/fontawesome-free/css/all.min.css" rel="stylesheet" type="text/css">
    <link
        href="https://fonts.googleapis.com/css?family=Nunito:200,200i,300,300i,400,400i,600,600i,700,700i,800,800i,900,900i"
        rel="stylesheet">

    <!-- Custom styles for this template-->
    <link href="css/sb-admin-2.css" rel="stylesheet">
    <link href="css/additional.css" rel="stylesheet">
    <script src="js/table.js"></script>

</head>

<body id="page-top" class="bg-gradient-info">

    <!-- Page Wrapper -->
    <div id="wrapper">

        <!-- Sidebar -->
        <ul class="navbar-nav bg-gradient-info sidebar sidebar-dark accordion" id="accordionSidebar">
                <div>
                    <img id="dashimg" src="img/logo2.png" alt="">
                </div>
            <!-- Divider -->
            <hr class="sidebar-divider my-0">

            <!-- Nav Item - Dashboard -->
            <li class="nav-item">
                <a class="nav-link" href="dashboard.php">
                    <i class="fas fa-fw fa-tachometer-alt"></i>
                    <span>Dashboard</span></a>
            </li>

            <!-- Divider -->
            <hr class="sidebar-divider">

            

            <!-- Nav Item - Charts -->
            <li class="nav-item">
                <a class="nav-link" href="registerPupil.php">
                    <i class="fas fa-fw fa-chart-area"></i>
                    <span>Register pupils</span></a>
            </li>
            <hr class="sidebar-divider">
            
            <!-- Nav Item - Tables -->
            <li class="nav-item">
                <a class="nav-link" href="assignment.php">
                    <i class="fas fa-fw fa-table"></i>
                    <span>Set assignment</span></a>
            </li>
            <hr class="sidebar-divider">

            <li class="nav-item active">
                <a class="nav-link" href="registeredPupil.php" onclick="return false;">
                    <i class="fas fa-fw fa-table"></i>
                    <span>Registered pupils</span></a>
            </li>
            <hr class="sidebar-divider">
            <li class="nav-item">
                <a class="nav-link" href="viewAssignment.php">
                    <i class="fas fa-fw fa-table"></i>
                    <span>View Assignment</span></a>
            </li>

            <li class="nav-item">
                <a class="nav-link" href="viewScores.php">
                    <i class="fas fa-fw fa-table"></i>
                    <span>View Scores</span></a>
            </li>
            
            <hr class="sidebar-divider">

            <li class="nav-item">
                <a class="nav-link" href="logout.php">
                    <i class="fas fa-fw fa-sign-out-alt"></i>
                    <span>Logout</span></a>
            </li>

            <!-- Divider -->
            <hr class="sidebar-divider d-none d-md-block">

        </ul>
    
        <div id="content-wrapper" class="d-flex flex-column">

            <!-- Main Content -->
            <div id="content">

                <div class="container-fluid">

                    <!-- Page Heading -->
                    <div class="d-sm-flex align-items-center justify-content-between mb-4">
                    <h1 class="h3 mb-0 text-primary" ><?php echo "Staff Id: ".$_SESSION['staffId']; ?></h1>
                       
                    </div>

                    <!-- Content Row -->
                    <div class="row">
                    <table  style="width: 1200px; line-height: 40px;">
        <tr>
            <th colspan="7" style="padding-left:370px"><h1>Pupils Registered</h1></th>
        </tr>
         <tr>
             <th>First name</th>
             <th>Last name</th>
             <th>Phone number</th>
             <th>User code</th>
             <th>Status</th>
             <th>Change Status</th>
             <th>Activation Request</th>
         </tr>
         <?php
         include "config.php";
         $query = "SELECT * FROM pupilsdetails ORDER BY firstName ASC";
         $result = mysqli_query($conn,$query);
         if (mysqli_num_rows($result)){
         while($rows = mysqli_fetch_assoc($result))
         {
         ?>
         <tr>
             <td><?php echo $rows['firstName']; ?></td>
             <td><?php echo $rows['lastName']; ?></td>
             <td><?php echo $rows['phoneNumber']; ?></td>
             <td><?php echo $rows['userCode']; ?></td>
             <td class="status"><?php 
             if ($rows['status']=="Activated")
             echo 'Activated';
             else
             echo 'Deactivated';
              ?></td>
             <td class="statusChange">
                 <?php
                  if($rows['status'] == "Activated"){
                    echo "<a href=deactivate.php?userCode=".$rows['userCode']." class='btn btn-danger' style='padding:0px 11px;'>Deactivate</a>";
                    }
                  if($rows['status'] == "Deactivated" && $rows['activationrequest']=="Requested"){
                 echo "<a href=activate.php?userCode=".$rows['userCode']." class='btn btn-success' style='padding:0px 20px;'>Activate</a>";
                 }
                 
                 ?>
             </td>
             <td class = 'activationRequest'><?php echo $rows['activationrequest']; ?></td>
         </tr>
         <?php
        }
    }
         ?>
         
    </table>
                    </div>

                </div>
                

            </div>
            

            <!-- Footer -->
            <footer class="sticky-footer bg-white">
                <div class="container my-auto">
                    <div class="copyright text-center my-auto">
                        <span>Copyright &copy; KINDERCARE2022</span>
                    </div>
                </div>
            </footer>
            

        </div>
       

    </div>
    
    <!-- Bootstrap core JavaScript-->
    <script src="vendor/jquery/jquery.min.js"></script>
    <script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>

    <!-- Core plugin JavaScript-->
    <script src="vendor/jquery-easing/jquery.easing.min.js"></script>

    <!-- Custom scripts for all pages-->
    <script src="js/sb-admin-2.min.js"></script>

    <!-- Page level plugins -->
    <script src="vendor/chart.js/Chart.min.js"></script>

    <!-- Page level custom scripts -->
    <script src="js/demo/chart-area-demo.js"></script>
    <script src="js/demo/chart-pie-demo.js"></script>

</body>

</html>
