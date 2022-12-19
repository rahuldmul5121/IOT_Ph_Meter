<?php

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "iot";
$ph="";
$suhu="";

if ($_GET ["ph"] || $_GET ["suhu"]){
    $ph = $_GET['ph'];
    $suhu = $_GET['suhu'];
}

$conn = mysqli_connect($servername, $username, $password, $dbname);

if($conn->connect_error){
    die("failed connection failed".$conn->connect_error);
}

$sql = "INSERT INTO data_ph_temperature(ph, suhu) value (".$ph.",".$suhu.")";
if($conn->query($sql    )==TRUE){
    echo "new record created !";
}
else{
    echo "failed insert record";
}

$conn->close();
exit;

?>