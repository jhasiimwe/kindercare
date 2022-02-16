<?php
include 'config.php';
session_start();
if(!isset($_SESSION["staffId"])){
    header('location:login.php');
}
?>
<!DOCTYPE html>
<html lang="en">

<head>


<style >
     tr:nth-child(even) {
        background-color: Lightblue;
    }
    </style>

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
            <li class="nav-item active">
                <a class="nav-link" href="dashboard.php" onclick="return false;">
                    <i class="fas fa-fw fa-tachometer-area"></i>
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
        <!-- End of Sidebar -->

        <!-- Content Wrapper -->
        <div id="content-wrapper" class="d-flex flex-column">

            <!-- Main Content -->
            <div id="content">

                <div class="container-fluid">

                    <!-- Page Heading -->
                    <div class="d-sm-flex align-items-center justify-content-between mb-4">
                        <h1 class="h3 mb-0 text-primary" ><?php echo "Staff Id: ".$_SESSION['staffId']; ?></h1>
                       
                    </div>

                     <div class="row">
                        <div class="col-xl-3 col-md-6 mb-4">
                            <div class="card border-left-primary shadow h-100 py-2">
                                <div class="card-body">
                                    <div class="row no-gutters align-items-center">
                                        <div class="col mr-2">
                                            <div class="text-xs font-weight-bold text-primary text-uppercase mb-1">
                                                Total pupils</div>
                                            <div class="h5 mb-0 font-weight-bold text-gray-800"><?php
                                             $query = "SELECT COUNT(*) FROM pupilsdetails ";
                                            $result = mysqli_query($conn,$query);
                                            //$count = $result ->fetch_column();
                                            $count = mysqli_fetch_row($result);
                                            print $count[0];
                                            ?></div>
                                        </div>
                                        <div class="col-auto">
                                            <i class="fas fa-calendar fa-2x text-gray-300"></i>
                                        </div>
                                    </div>
                                </div>
                            </div>
                       </div> 

                        <!-- Earnings (Monthly) Card Example -->
                        <div class="col-xl-3 col-md-6 mb-4">
                            <div class="card border-left-success shadow h-100 py-2">
                                <div class="card-body">
                                    <div class="row no-gutters align-items-center">
                                        <div class="col mr-2">
                                            <div class="text-xs font-weight-bold text-success text-uppercase mb-1">
                                                Deactivated pupils</div>
                                            <div class="h5 mb-0 font-weight-bold text-gray-800"><?php
                                            $query = "SELECT COUNT(*) FROM pupilsdetails WHERE status = 'Deactivated'";
                                            $result = mysqli_query($conn,$query);
                                            //$count = $result ->fetch_column();
                                            $count = mysqli_fetch_row($result);
                                            print $count[0];
                                            ?></div>
                                        </div>
                                        <div class="col-auto">
                                            <i class="fas fa-dollar-sign fa-2x text-gray-300"></i>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>

                        <!-- Earnings (Monthly) Card Example -->
                        <div class="col-xl-3 col-md-6 mb-4">
                            <div class="card border-left-info shadow h-100 py-2">
                                <div class="card-body">
                                    <div class="row no-gutters align-items-center">
                                        <div class="col mr-2">
                                            <div class="text-xs font-weight-bold text-info text-uppercase mb-1">Active pupils
                                            </div>
                                            <div class="row no-gutters align-items-center">
                                                <div class="col-auto">
                                                    <div class="h5 mb-0 mr-3 font-weight-bold text-gray-800">
                                                    <?php 
                                                    $query = "SELECT COUNT(*) FROM pupilsdetails WHERE status = 'Activated'";
                                                    $result = mysqli_query($conn,$query);
                                                    //$count = $result ->fetch_row();
                                                    $count = mysqli_fetch_row($result);
                                                    //$count1 = $count ->serialize();
                                                    print $count[0];
        
                                                    ?>

                                                    </div>
                                                </div>
                                                <div class="col">
                                                    
                                                </div>
                                            </div>
                                        </div>
                                        <div class="col-auto">
                                            <i class="fas fa-clipboard-list fa-2x text-gray-300"></i>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>

                    </div>

                </div>
                

            </div>
            <div>

            <div class="row">
            <table style="width: 150px; line-height: 40px; margin-left:310px;">
            <tr>
            <th colspan="2" style="padding-right:200px"><h1>Attempts</h1></th>
            </tr>
            <tr>
             <th>Assignment Id</th>
             <th>Attempts</th>
         </tr>
         <?php
         //include "config.php"
         $query = "SELECT * FROM asssignmentdetails";
         $result = mysqli_query($conn,$query);
         if (mysqli_num_rows($result)){
         while($rows = mysqli_fetch_assoc($result))
         {
         ?>
         <tr>
             <td><?php echo $rows['assignmentId']; ?></td>
             <td>  
                 <?php
                 $query = "SELECT COUNT(*) FROM scores WHERE assignmentId =" .$rows['assignmentId'];
                 $result1 = mysqli_query($conn,$query);
                 $row = mysqli_fetch_row($result1);
                 print($row[0]);
                 //mysqli_close($conn);
                 ?>
             </td>
         </tr>
        
         <?php
             }
        }
        ?>

        </table>
         </div>
            <div id="chart-container">
      <canvas id="mycanvas"></canvas>
    </div>

    <!-- javascript -->
    <script type="text/javascript" src="js/jquery.min.js"></script>
    <script type="text/javascript" src="js/Chart.min.js"></script>
    <script type="text/javascript" src="js/app.js"></script>

            

            <!-- <h1>Pupil's performance</h1> -->
    <!-- <div id="chart"></div>
    <script type="text/javascript">
        var chart = am4core.createFromConfig({
            // Create pie series
            "series": [{
                "type": "PieSeries",
                "dataFields": {
                    "value": "marks",
                    "category": "name"
                }
            }],
            // Add data
            "data": [
                {
                    "name": "Wabwiire",
                    "marks": 70
                },
                {
                    "name": "Lwanga Kaye",
                    "marks": 20
                },
                {
                    "name": "Mayambala",
                    "marks": 10
                },
               
                    
            ],
            // And, for a good measure, let's add a legend
            "legend": {}

        }, "chart", "PieChart");
    </script> -->
      <canvas id="myBarChart" width="250" height="300"></canvas> 
    </div>  
             <!-- <canvas id="myChart" width="400" height="400"></canvas> -->
             <!--  <div id="myChart" width="400" height="400"></div> -->
            <!-- <div id="piechart" style="width: 900px; height: 500px;"></div> --> 
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
     <!-- <script src="js/demo/chart-bar-demo.js"></script>  -->

    
</body>
</html>

