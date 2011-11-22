var canvas;
var ctx;
var timerDrawID;  //�`��^�C�}�[ID
var cW = 150;  //�L�����o�X���T�C�Y
var cH = 150;  //�L�����o�X�c�T�C�Y
var mouseDownFlag = false;  //�}�E�X�_�E�����Ă��邩�ǂ���
var mouseX1;  //�h���b�O�J�n�������W
var mouseY1;  //�h���b�O�J�n�������W
var mouseX2;  //�h���b�O���̍��W
var mouseY2;  //�h���b�O���̍��W
var dragDivX;  //�h���b�O�J�n�n�_�ƌ��݂̍�
var dragDivY;  //�h���b�O�J�n�n�_�ƌ��݂̍�
var obj;
//���[�U�[�G�[�W�F���g
var isiPad;
var isiPhone;

function joy_init(){
  //�L�����o�X�̏�������
  canvas = document.getElementById('joyCanvas');
  if ( ! canvas || ! canvas.getContext ) return false;
  //2D�R���e�L�X�g
  ctx = canvas.getContext('2d');
  //�C�x���g
  canvas.addEventListener("mousedown", mouseDownListner, false);
  canvas.addEventListener("mousemove", mouseMoveListner, false);
  canvas.addEventListener("mouseup", mouseUpListner, false);
  canvas.addEventListener("mouseout", mouseUpListner, false);
  canvas.addEventListener("touchstart", mouseDownListner, false);
  canvas.addEventListener("touchmove", mouseMoveListner, false);
  canvas.addEventListener("touchend", mouseUpListner, false);
  canvas.addEventListener("touchcancel", mouseUpListner, false);
  //�I�u�W�F�N�g
  obj = new Object();
  obj.w = 40;
  obj.h = 40;
  obj.x = cW*0.5 - obj.w * 0.5;
  obj.y = cH*0.5 - obj.h * 0.5;

  //���[�U�[�G�[�W�F���g
  isiPad = navigator.userAgent.match(/iPad/i) != null;
  isiPhone = navigator.userAgent.match(/iPhone/i) != null;

  //�^�C�}�[�J�n
  setTimerDraw();
}

function setTimerDraw(){
  clearInterval(timerDrawID);
  timerDrawID = setInterval("joy_draw()", 100);
}

function joy_draw() {
  //�\���N���A
  ctx.clearRect(0, 0, cW, cH);
  ctx.fillStyle="#000000";
  ctx.beginPath();

  ctx.rect(10, 10, cW-20, cH-20);
  ctx.rect(30, 30, cW-60, cH-60);
  ctx.rect(50, 50, cW-100, cH-100);

  ctx.moveTo(0,cH*0.5);
  ctx.lineTo(cW,cH*0.5);
  ctx.moveTo(cW*0.5,0);
  ctx.lineTo(cW*0.5,cH);
  ctx.stroke();

  //�摜��`��
  if (mouseDownFlag) {
    ctx.fillStyle="#FF0000";
    ctx.fillRect(obj.x + dragDivX, obj.y + dragDivY, obj.w, obj.h);
  } else {
    ctx.fillRect(obj.x, obj.y, obj.w, obj.h);
  }
}

function twistMsg(x, z) {
  return '{"linear":{"x":' + x + ',"y":0,"z":0}, "angular":{"x":0,"y":0,"z":' + z + '}}';
}

//�}�E�X�C�x���g
function mouseDownListner(e) {
  var rect = e.target.getBoundingClientRect();
  //���W�擾
  if (isiPad || isiPhone) {
    //iPad & iPhone�p����
    mouseX1 = e.touches[0].pageX - rect.left;
    mouseY1 = e.touches[0].pageY - rect.top;
  } else {
    //PC�p����
    mouseX1 = e.clientX - rect.left;
    mouseY1 = e.clientY - rect.top;
  }
  if (mouseX1 > obj.x && mouseX1 < obj.x + obj.w) {
    if (mouseY1 > obj.y && mouseY1 < obj.y + obj.h) {
      dragDivX = 0;
      dragDivY = 0;
      mouseDownFlag = true;
    }
  }
}

function mouseMoveListner(e) {
  e.preventDefault();
  if (mouseDownFlag) {
    //�c�X�N���[�������Ȃ��iiPad & iPhone�j
    //���W�擾
    var rect = rect = e.target.getBoundingClientRect();
    if (isiPad || isiPhone) {
      //iPad & iPhone�p����
      mouseX2 = e.touches[0].pageX - rect.left;
      mouseY2 = e.touches[0].pageY - rect.top;
    } else {
      //PC�p����
      mouseX2 = e.clientX - rect.left;
      mouseY2 = e.clientY - rect.top;
    }
    if (mouseX2 < 0 || mouseX2 > cW || mouseY2 < 0 || mouseY2 > cH) {
      dragEnd();
    }
    dragDivX = (mouseX2 - mouseX1);
    dragDivY = (mouseY2 - mouseY1);
    // ROS
    connection.publish('/cmd_vel', 'geometry_msgs/Twist', twistMsg(dragDivY * 0.001, dragDivX * -0.003));
  }
}

function mouseUpListner(e) {
  dragEnd();
}

function dragEnd() {
  mouseDownFlag = false;
  obj.x = cW*0.5 - obj.w*0.5;
  obj.y = cH*0.5 - obj.h*0.5;
  connection.publish('/cmd_vel', 'geometry_msgs/Twist', twistMsg(0, 0));
  connection.publish('/cmd_vel', 'geometry_msgs/Twist', twistMsg(0, 0));

}
