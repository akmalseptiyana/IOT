<?php
if (isset($_GET['led']) && isset($_GET['state'])) {
    require 'koneksi.php';
    $state = $_GET['state'];
    $led = $_GET['led'];

    if ($led == '1') {
        mysqli_query($conn, "UPDATE led SET led1 = '$state'");
    } else if ($led == '2') {
        mysqli_query($conn, "UPDATE led SET led2 = '$state'");
    }
    header('Location: index.php');
    exit;
}
