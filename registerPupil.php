<?php  session_start();
if(!isset($_SESSION["staffId"])){
    header('location:login.php');
   
}
include 'config.php';
?>
<!DOCTYPE html>
<html lang="en">
<head>

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta name="description" content="">
    <meta name="author" content="">

<script>
    function validation(){
        var fname = document.forms["RegPupil"]["fname"];
        var lname = document.forms["RegPupil"]["lname"];
        var pnumber = document.forms["RegPupil"]["pnumber"];

        if(fname.value=""){
            window.alert("Please enter your first name");
            fname.focus();
            return false;
        }

        if(fname.value=""){
            window.alert("Please enter your last name");
            lname.focus();
            return false;
        }

        if(fname.value=""){
            window.alert("Please enter your phone number");
            pnumber.focus();
            return false;
        }
        return true;
    }
    </script>

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
            <li class="nav-item active">
                <a class="nav-link" href="" onclick="return false;">
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

            <li class="nav-item">
                <a class="nav-link" href="viewAssignment.php">
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
      
        <div id="content-wrapper" class="d-flex flex-column">

            <!-- Main Content -->
            <div id="content">

                <div class="container-fluid">

                    <!-- Page Heading -->
                    <div class="d-sm-flex align-items-center justify-content-between mb-4">
                        <h1 class="h3 mb-0 text-primary"><?php echo "Staff Id: ".$_SESSION['staffId']; ?></h1>
                       
                    </div>

                    <!-- Content Row -->
                    <form name = "RegPupil" action="registeredPupil.php" onsubmit="return validation" method = "post">
                        <div class="row">
                            <p class="text-primary">Register pupil</p>
                        </div>
                    <div class="row">
                    <br>
                        <div class=col-lg-8>
                            <div class="form-group">
                                <input type="text" name="fname" class="form-control form-control-user"
                                    id="exampleInputEmail" aria-describedby="emailHelp"
                                    placeholder="First name">
                            </div>
                        
                        <div class="form-group">
                            <input type="text" name="lname" class="form-control form-control-user"
                                id="exampleInputEmail" aria-describedby="emailHelp"
                                placeholder="Last name">
                        </div>
                        <div class="form-group">
                            <input type="text" name="pnumber" class="form-control form-control-user"
                                id="exampleInputEmail" aria-describedby="emailHelp"
                                placeholder="Phone number">
                        </div>
                        <div class="form-group">
                    <?php
                       $query = "SELECT COUNT(*) FROM pupilsdetails";
                       $result = mysqli_query($conn,$query);
                       $count = $result ->fetch_row();
                       $count=intVal($count[0]);
                       $count +=1;
                       $count = 'KESP'.$count; 
                                                    //$count1 = $count ->serialize();
                       echo 'The next available userCode is: '."<span class='text-primary'>".$count."</span>";
        
                      echo" <input type='text' name='usercode' class='form-control form-control-user'
                       id='exampleInputEmail' aria-describedby='emailHelp' value = '$count'>";
                    ?>  
                        </div>
                        <button type="submit" class="btn btn-primary" value="Register" name="register">Register</button>
                    </div>
                    </div>
                </form>
                </div>
                

            </div>
        
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
