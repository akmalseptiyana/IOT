<?php
if (isset($_POST['token'])) {
    require 'koneksi.php';
    $key = $_POST['token'];

    $sql = mysqli_query($conn, "SELECT * FROM led WHERE token = '$key'");
    $query = mysqli_num_rows($sql);

    if ($query > 0) {
        $data = mysqli_fetch_assoc($sql);
    } else {
        $data = ["token" => "Not Valid"];
    }

    $respon = json_encode($data);
    echo $respon;
}
