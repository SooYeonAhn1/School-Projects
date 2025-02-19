<?php
if (isset($_POST['submit']))
(
  $img = $_FILES['images']['name'];
  $img_loc = $_FILES['images']['temp_name'];
  $img_folder = 'input_folder/'
  if (move_uploaded_file($img_loc,$img_folder.$img))
  (
    ?>
    <script>alert("file uploaded, please click boundingbox button")</script>
    <?php
  )
  else (
    ?>
     <script>alert("doesn't work")</script>
     <?php
   )
  // header("Location:");
)
?>
