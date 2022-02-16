<?php
session_start();
if(!isset($_SESSION["staffId"])){
    header('location:login.php');
}
?>
<?php
include 'config.php';
if(isset($_POST["submit"])){
 $expiry_date=$_POST['dat'];
$expiry_time=$_POST['tim'];
$assign = $_POST['assign'];

      $table = "INSERT INTO asssignmentdetails (expiryDate, expiryTime, assignment) ".
               "VALUES ('$expiry_date', '$expiry_time', '$assign')";
      mysqli_query($conn,$table);
}
?>
<!DOCTYPE html>
<html lang="en">
<head>

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta name="description" content="">
    <meta name="author" content="">

    <title>KINDERCARE</title>

    <!-- Custom fonts for this template-->
    <link href="vendor/fontawesome-free/css/all.min.css" rel="stylesheet" type="text/css">
    <link
        href="https://fonts.googleapis.com/css?family=Nunito:200,200i,300,300i,400,400i,600,600i,700,700i,800,800i,900,900i"
        rel="stylesheet">

    <!-- Custom styles for this template-->
    <link href="css/sb-admin-2.css" rel="stylesheet">
    <link href="css/additional.css" rel="stylesheet">

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
                    <span>Register pupil</span></a>
            </li>
            <hr class="sidebar-divider">
            
            <!-- Nav Item - Tables -->
            <li class="nav-item">
                <a class="nav-link" href="assignment.php">
                    <i class="fas fa-fw fa-table"></i>
                    <span>Set assignment</span></a>
            </li>
            <hr class="sidebar-divider">

            <li class="nav-item">
                <a class="nav-link" href="registeredPupil.php">
                    <i class="fas fa-fw fa-table"></i>
                    <span>Registered pupils</span></a>
            </li>

            <hr class="sidebar-divider">
            <li class="nav-item active">
                <a class="nav-link" href="viewAssignment.php" onclick="return false;">
                    <i class="fas fa-fw fa-table"></i>
                    <span>View Assignment</span></a>
            </li>
            <hr class="sidebar-divider">

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
        <!-- End of Sidebar -->

        <!-- Content Wrapper -->
        <div id="content-wrapper" class="d-flex flex-column">

            <!-- Main Content -->
            <div id="content">

                <!-- Topbar -->
               
                <!-- End of Topbar -->

                <!-- Begin Page Content -->
                <div class="container-fluid">

                    <!-- Page Heading -->
                    <div class="d-sm-flex align-items-center justify-content-between mb-4">
                        <h1 class="h3 mb-0 text-primary"><?php echo "Staff Id: ".$_SESSION['staffId']; ?></h1>
                       
                    </div>

                    <div class="row">
                    <table  style="width: 1200px; line-height: 40px;">
        <tr>
            <th colspan="6" style="padding-left:370px"><h1>Assignments</h1></th>
        </tr>
         <tr>
             <th>Assignment Id</th>
             <th>Assignment</th>
             <th>Expiry date</th>
             <th>Expiry time</th>
         </tr>
         <?php
         //include "config.php";
         $currentDate = date("Y-m-d");
         //echo  $currentDate;
         $query = "SELECT * FROM asssignmentdetails ORDER BY assignmentId DESC";
         $result = mysqli_query($conn,$query);
         if (mysqli_num_rows($result)){
         while($rows = mysqli_fetch_assoc($result))
         {
         ?>
         <tr>
             <td><?php echo $rows['assignmentId']; ?></td>
             <td><?php echo $rows['assignment']; ?></td>
             <td><?php echo $rows['expiryDate']; ?></td>
             <td><?php echo $rows['expiryTime']; ?></td>
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