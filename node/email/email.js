let nodemailer = require('nodeMailer');
const cron = require('node-cron');
const schedule = require('node-schedule');
let constants = require('./constants');

function buildDate(){

  let date = new Date();
  let fullYear = date.getFullYear();
  let day = ("0" + date.getDay()).slice(-2);
  let month = ("0" + (date.getMonth() + 1)).slice(-2);

  return   day + "-" + month + "-" + fullYear;

}

const url_taskMap = {};
let i = 0;
const campaignId = "MY_CUSTOM_ID"
let job = schedule.scheduleJob(campaignId, "* * * * * *",function(){
  console.log("Scheduler running...");
  if(i == 5){
  	process.exit();
  }
  i++;
  })

let current = schedule.scheduledJobs[campaignId];
console.log(current);
if(i == 5){
	current.cancel();
}
//const task = cron.schedule("* * * * * *",function(){
//  console.log("Scheduler running...");
//  i++;

  /*var transporter = nodemailer.createTransport({
    host: 'smtp.aol.com',
    port: '587', 
    auth: {
        service: 'aol',
        user: 'test2211',
        pass: constants.pass
    }
  });
  
  var mailOptions = {
    from: 'test2211@aol.com',
    to: 'c908453@urhen.com',
    subject: 'News letter - ' + buildDate(),
    html: '<h1>Todays topics include...</h1>'
  };
  
  transporter.sendMail(mailOptions, function(error, info){
    if (error) {
      console.log(error);
    } else {
      console.log('Email sent: ' + info.response);
    }
  }); */
//});

//	url_taskMap[0] = task;
//	let job = url_taskMap[0];
//	if(i == 5){
//		job.stop();
//	}

