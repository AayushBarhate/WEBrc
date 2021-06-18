
const char webpageCode[] PROGMEM =
R"=====(
<!DOCTYPE HTML>
<html>
<head>
  <title>WEBrc</title>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
</head>
<!-------------------------------C S S------------------------------>
<style>
  .button{
  user-select: none;
  -moz-user-select: none;
  -webkit-user-select: none;
  -ms-user-select: none;
  display: inline-block;
  padding: 15px 35px;
  font-size: 24px;
  cursor: pointer;
  text-align: center;
  text-decoration: none;
  outline: none;
  color: #fff;
  background-color: #4CAF50;
  border: none;
  border-radius: 15px;
  box-shadow: 0 9px #999;
  }
   .button:hover {background-color: #3e8e41}

  .button:active {
  background-color: #3e8e41;
  box-shadow: 0 5px #666;
  transform: translateY(4px);
   }

</style>
<!------------------------------H T M L----------------------------->
<body>
  <!--<a id="button" ONCLICK='button()'> </a>------>

  <button class="button" style="position: relative; height: 15vh; border: 0px solid green;  margin: 0;   position: fixed;   top: 30vh;   left: 25vw;" onmousedown='Front()' ontouchstart='Front()' ontouchend='Stop()' onmouseup='Stop()'>Drive</button>

  
  <button class="button" style="position: relative; height: 15vh; border: 0px solid green;  margin: 0;   position: fixed;   top: 50vh;   left: 25vw;" onmousedown='Back()' ontouchstart='Back()' ontouchend='Stop()' onmouseup='Stop()'>Back</button>


  <button class="button" style="position: relative; height: 15vh; border: 0px solid green;  margin: 0;   position: fixed;   top: 40vh;   left: 45vw;" onmousedown='Right()' ontouchstart='Right()' ontouchend='SteerStop()' onmouseup='SteerStop()'>Left</button>


  <button class="button" style="position: relative; height: 15vh; border: 0px solid green;  margin: 0;   position: fixed;   top: 40vh;   left: 60vw;" onmousedown='Left()' ontouchstart='Left()' ontouchend='SteerStop()' onmouseup='SteerStop()'>Right</button>

<!-----------------------------JavaScript--------------------------->
  <script>
     InitWebSocket()
     function InitWebSocket()
     {
       websock = new WebSocket('ws://'+window.location.hostname+':81/'); 
       websock.onmessage = function(evt)
       {
          JSONobj = JSON.parse(evt.data);
       }
     }
     //-------------------------------------------------------------
     function Front()
     {
         forw = 'Front=1';
        websock.send(forw);
     }
     function Back()
     {
        forw1 = 'Front=2';
        websock.send(forw1);
     }
     function Stop()
     {
        forw0 = 'Front=0';
        websock.send(forw0);
     }
     function Left()
     {
        st = 'Steer=1';
        websock.send(st);
     }
     function Right()
     {
        st1 = 'Steer=2';
        websock.send(st1);
     }
     function SteerStop()
     {
        st0 = 'Steer=0';
        websock.send(st0);
     }
  </script>
</body>
</html>
)=====";
