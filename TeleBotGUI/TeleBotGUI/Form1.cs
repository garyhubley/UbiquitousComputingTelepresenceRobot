using System;
using System.Net;
using System.Windows.Forms;
using uPLibrary.Networking.M2Mqtt;
using uPLibrary.Networking.M2Mqtt.Messages;
using System.Text;
namespace TeleBotGUI
{
    public partial class TeleBot : Form
    {
        MqttClient client;

        public TeleBot()
        {
            InitializeComponent();
            // create client instance 
            client = new MqttClient("iot.eclipse.org");
           

        }

        private void LeftButton_Click(object sender, EventArgs e)
        {
            if (client.IsConnected)
                client.Publish("csci/telerobot/group2", Encoding.UTF8.GetBytes("rotate_anti_clockwise"));
            else
                MessageBox.Show("Please connect the controller first");
        }

        private void UpButton_Click(object sender, EventArgs e)
        {
            if (client.IsConnected)
                client.Publish("csci/telerobot/group2", Encoding.UTF8.GetBytes("move_up"));
            else
                MessageBox.Show("Please connect the controller first");
        }

        private void DownButton_Click(object sender, EventArgs e)
        {
            if (client.IsConnected)
                client.Publish("csci/telerobot/group2", Encoding.UTF8.GetBytes("move_down"));
            else
                MessageBox.Show("Please connect the controller first");
        }

        private void RightButton_Click(object sender, EventArgs e)
        {
            if (client.IsConnected)
                client.Publish("csci/telerobot/group2", Encoding.UTF8.GetBytes("rotate_clockwise"));
            else
                MessageBox.Show("Please connect the controller first");
        }

        private void QuestionButton_Click(object sender, EventArgs e)
        {
            if (client.IsConnected)
                client.Publish("csci/telerobot/group2", Encoding.UTF8.GetBytes("question_ask_led"));
            else
                MessageBox.Show("Please connect the controller first");
        }

        private void ConnectButton_Click(object sender, EventArgs e)
        {
           
            // register to message received 
            //client.MqttMsgPublishReceived += new MqttClient.MqttMsgPublishEventHandler(client_MqttMsgPublishReceived);

            string clientId = Guid.NewGuid().ToString();
            client.Connect(clientId);


            var S1 = new string[] { "csci/telerobot/group2" };
            // subscribe to the topic "/home/temperature" with QoS 2 
            client.Subscribe(S1, new byte[] { MqttMsgBase.QOS_LEVEL_EXACTLY_ONCE });

            //client.Publish("csci/telerobot/group2", Encoding.UTF8.GetBytes("hi its done"));

        }

        static void client_MqttMsgPublishReceived(object sender, MqttMsgPublishEventArgs e)
        {

            String a = System.Text.Encoding.UTF8.GetString(e.Message);
            //myUI(System.Text.Encoding.UTF8.GetString(e.Message), MessageTextBox);
        }
    }
}
