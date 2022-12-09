var ctx;
var date;
var size = 80;

function start() 
{
    var canvas = document.getElementById('canvas');
    ctx = canvas.getContext('2d');
    showTime();
    //call the function every second
    setInterval(showTime, 1000);
}
function showTime()
{
    //clear the canvas
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    //get the date
    date = new Date();
    //draw the clock
    drawClock();
    //show the time
    showSeconds();
    showMinutes();
    showHours();
}
function drawClock() 
{
    //draw the frame
    ctx.beginPath();
    ctx.arc(canvas.width / 2, canvas.height / 2, size + 7, 0, Math.PI * 2);
    ctx.fillStyle = "#fff";
    ctx.fill();
    ctx.strokeStyle = '#3b3b3b';
    ctx.lineWidth = 10;
    ctx.stroke();
    
    //draw the hour marks
    for (var i = 0; i < 12; i++) {
        var angle = (i - 3) * (Math.PI * 2) / 12;      
        ctx.lineWidth = 2;            
        ctx.beginPath();
        var x1 = (canvas.width / 2) + Math.cos(angle) * (size);
        var y1 = (canvas.height / 2) + Math.sin(angle) * (size);
        var x2 = (canvas.width / 2) + Math.cos(angle) * (size - (size / 7));
        var y2 = (canvas.height / 2) + Math.sin(angle) * (size - (size / 7));
        ctx.moveTo(x1, y1);
        ctx.lineTo(x2, y2);
        ctx.strokeStyle = '#000';
        ctx.stroke();
    }
    
    //draw the second marks
    for (i = 0; i < 60; i++) {
        angle = (i - 3) * (Math.PI * 2) / 60;      
        ctx.lineWidth = 1;           
        ctx.beginPath();
        x1 = (canvas.width / 2) + Math.cos(angle) * (size);
        y1 = (canvas.height / 2) + Math.sin(angle) * (size);
        x2 = (canvas.width / 2) + Math.cos(angle) * (size - (size / 30));
        y2 = (canvas.height / 2) + Math.sin(angle) * (size - (size / 30));
        ctx.moveTo(x1, y1);
        ctx.lineTo(x2, y2);
        ctx.strokeStyle = '#000';
        ctx.stroke();
    }
}
function showSeconds() 
{
    var sec = date.getSeconds();
    var angle = ((Math.PI * 2) * (sec / 60)) - ((Math.PI * 2) / 4);
    ctx.lineWidth = 2;             
    ctx.beginPath();
    ctx.moveTo(canvas.width / 2, canvas.height / 2);   
    ctx.lineTo((canvas.width / 2 + Math.cos(angle) * size), canvas.height / 2 + Math.sin(angle) * size);
    ctx.moveTo(canvas.width / 2, canvas.height / 2);   
    ctx.lineTo((canvas.width / 2 - Math.cos(angle) * 20), canvas.height / 2 - Math.sin(angle) * 20);
    ctx.strokeStyle = '#e10600';       
    ctx.stroke();
}
function showMinutes() 
{
    var min = date.getMinutes();
    var angle = ((Math.PI * 2) * (min / 60)) - ((Math.PI * 2) / 4);
    ctx.lineWidth = 4;             
    ctx.beginPath();
    ctx.moveTo(canvas.width / 2, canvas.height / 2);  
    ctx.lineTo((canvas.width / 2 + Math.cos(angle) * size / 1.1),      
    canvas.height / 2 + Math.sin(angle) * size / 1.1);
    ctx.strokeStyle = '#000'; 
    ctx.stroke();
}
function showHours() 
{
    var hour = date.getHours();
    var min = date.getMinutes();
    var angle = ((Math.PI * 2) * ((hour * 5 + (min / 60) * 5) / 60)) - ((Math.PI * 2) / 4);
    ctx.lineWidth = 6;           
    ctx.beginPath();
    ctx.moveTo(canvas.width / 2, canvas.height / 2);     
    ctx.lineTo((canvas.width / 2 + Math.cos(angle) * size / 1.5),      
    canvas.height / 2 + Math.sin(angle) * size / 1.5);
    ctx.strokeStyle = '#000'; 
    ctx.stroke();
}