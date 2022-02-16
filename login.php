<?php
session_start();
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
    <style>
        .bg-login-image{
            padding-bottom: 20px;
            background:url("img/logo2.png");
            background-position: center;
            background-size:500px 550px;
            background-repeat: no-repeat;
        }
    </style>

</head>

<body class="bg-gradient-info">

    <div class="container">

        <!-- Outer Row -->
        <div class="row justify-content-center">

            <div class="col-xl-10 col-lg-12 col-md-9">

                <div class="card o-hidden border-0 shadow-lg my-5">
                    <div class="card-body p-0">
                        <!-- Nested Row within Card Body -->
                       
                        <div class="row">
                            <div class="col-lg-6 d-none d-lg-block bg-login-image"></div>
                            <div class="col-lg-6">
                                <div class="p-5">
                                    <div class="text-center">
                                        <h2 class="text-success mb-4">WELCOME TO <br>
                                        <b>KINDERCARE</b> <br> E-LEARNING SYSTEM</h2>
                                        <P class="text-primary">LOGIN IN AS TEACHER TO CONTINUE</P>
                                        <p id="demo" class = "text-danger"></p>
                                    </div>
                                    <form action="login.php" method="post">
                                        <div class="form-group">
                                            <input type="text" name="staffId" class="form-control form-control-user"
                                                id="exampleInputEmail" aria-describedby="emailHelp"
                                                placeholder="Enter staff Id" required>
                                        </div>
                                        <div class="form-group">
                                            <input type="password" name="password" class="form-control form-control-user"
                                                id="exampleInputPassword" placeholder="Password" required>
                                        </div>
            
                                        <input type="submit" name="submit" class="btn btn-success btn-user btn-block" value="Login">
                                         <p>NEW TEACHER? <a href="signup.php">signup</a></p>
                                        <hr>
                                    </form>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>

            </div>

        </div>

    </div>

    <!-- Bootstrap core JavaScript-->
    <script src="vendor/jquery/jquery.min.js"></script>
    <script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>

    <!-- Core plugin JavaScript-->
    <script src="vendor/jquery-easing/jquery.easing.min.js"></script>

    <!-- Custom scripts for all pages-->
    <script src="js/sb-admin-2.min.js"></script>

</body>

</html>
<?php
if(isset($_POST['submit'])){
    include 'config.php';
    $staffId = $_POST['staffId']; 
    $password =  $_POST['password'];
    echo($staffId);
    $query1 = "SELECT *
     FROM teachersdetail WHERE staffId = '$staffId' AND passcode = '$password' limit 1";
    $result= mysqli_query($conn, $query1);

    if(mysqli_num_rows($result)==1){
     $teacher = mysqli_fetch_assoc($result);
     $_SESSION["staffId"] = $_POST['staffId'];
         header('location:dashboard.php');
     }
    else {
        echo ('
        <script>
     par = document.getElementById("demo");
     par.innerHTML= "WRONG USERNAME OR PASSWORD";
     </script>');
    }
}
?>
