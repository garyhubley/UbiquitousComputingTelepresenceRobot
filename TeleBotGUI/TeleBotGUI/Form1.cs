using System;
using System.Net;
using System.Windows.Forms;
using uPLibrary.Networking.M2Mqtt;

namespace TeleBotGUI
{
    public partial class TeleBot : Form
    {
        public TeleBot()
        {
            InitializeComponent();
        }

        private void LeftButton_Click(object sender, EventArgs e)
        {

        }

        private void UpButton_Click(object sender, EventArgs e)
        {

        }

        private void DownButton_Click(object sender, EventArgs e)
        {

        }

        private void RightButton_Click(object sender, EventArgs e)
        {

        }

        private void QuestionButton_Click(object sender, EventArgs e)
        {

        }

        private void ConnectButton_Click(object sender, EventArgs e)
        {
            // create client instance 
            MqttClient client = new MqttClient("iot.eclipse.org"/*MQTT_BROKER_ADDRESS*/);

            // register to message received 
            client.MqttMsgPublishReceived += client_MqttMsgPublishReceived;
            
            string clientId = Guid.NewGuid().ToString();
            client.Connect(clientId);

            // subscribe to the topic "/home/temperature" with QoS 2 
            client.Subscribe(new string[] { "/home/temperature" }, new byte[] { MqttMsgBase.QOS_LEVEL_EXACTLY_ONCE }); 
 
        }

        static void client_MqttMsgPublishReceived(object sender, MqttMsgPublishEventArgs e)
        {
            // handle message received 
        }
    }
}
