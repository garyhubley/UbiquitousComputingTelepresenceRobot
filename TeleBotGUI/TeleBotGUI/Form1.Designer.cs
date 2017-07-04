namespace TeleBotGUI
{
    partial class TeleBot
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TeleBot));
            this.LeftButton = new System.Windows.Forms.Button();
            this.UpButton = new System.Windows.Forms.Button();
            this.RightButton = new System.Windows.Forms.Button();
            this.DownButton = new System.Windows.Forms.Button();
            this.QuestionButton = new System.Windows.Forms.Button();
            this.ConnectButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // LeftButton
            // 
            this.LeftButton.Dock = System.Windows.Forms.DockStyle.Left;
            this.LeftButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Red;
            this.LeftButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.LeftButton.Location = new System.Drawing.Point(0, 0);
            this.LeftButton.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.LeftButton.Name = "LeftButton";
            this.LeftButton.Size = new System.Drawing.Size(80, 502);
            this.LeftButton.TabIndex = 0;
            this.LeftButton.Text = "←";
            this.LeftButton.UseVisualStyleBackColor = true;
            this.LeftButton.Click += new System.EventHandler(this.LeftButton_Click);
            // 
            // UpButton
            // 
            this.UpButton.AutoSize = true;
            this.UpButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Red;
            this.UpButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.UpButton.Location = new System.Drawing.Point(80, 0);
            this.UpButton.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.UpButton.Name = "UpButton";
            this.UpButton.Size = new System.Drawing.Size(408, 80);
            this.UpButton.TabIndex = 1;
            this.UpButton.Text = "↑";
            this.UpButton.UseVisualStyleBackColor = true;
            this.UpButton.Click += new System.EventHandler(this.UpButton_Click);
            // 
            // RightButton
            // 
            this.RightButton.Dock = System.Windows.Forms.DockStyle.Right;
            this.RightButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Red;
            this.RightButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.RightButton.Location = new System.Drawing.Point(488, 0);
            this.RightButton.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.RightButton.Name = "RightButton";
            this.RightButton.Size = new System.Drawing.Size(80, 502);
            this.RightButton.TabIndex = 2;
            this.RightButton.Text = "→";
            this.RightButton.UseVisualStyleBackColor = true;
            this.RightButton.Click += new System.EventHandler(this.RightButton_Click);
            // 
            // DownButton
            // 
            this.DownButton.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.DownButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Red;
            this.DownButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.DownButton.Location = new System.Drawing.Point(80, 422);
            this.DownButton.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.DownButton.Name = "DownButton";
            this.DownButton.Size = new System.Drawing.Size(408, 80);
            this.DownButton.TabIndex = 3;
            this.DownButton.Text = "↓";
            this.DownButton.UseVisualStyleBackColor = true;
            this.DownButton.Click += new System.EventHandler(this.DownButton_Click);
            // 
            // QuestionButton
            // 
            this.QuestionButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Red;
            this.QuestionButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.QuestionButton.Location = new System.Drawing.Point(202, 279);
            this.QuestionButton.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.QuestionButton.Name = "QuestionButton";
            this.QuestionButton.Size = new System.Drawing.Size(166, 83);
            this.QuestionButton.TabIndex = 4;
            this.QuestionButton.Text = "Ask Question";
            this.QuestionButton.UseVisualStyleBackColor = true;
            this.QuestionButton.Click += new System.EventHandler(this.QuestionButton_Click);
            // 
            // ConnectButton
            // 
            this.ConnectButton.BackColor = System.Drawing.Color.Red;
            this.ConnectButton.Location = new System.Drawing.Point(202, 138);
            this.ConnectButton.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.ConnectButton.Name = "ConnectButton";
            this.ConnectButton.Size = new System.Drawing.Size(166, 83);
            this.ConnectButton.TabIndex = 5;
            this.ConnectButton.Text = "Connect to \r\ncontroller";
            this.ConnectButton.UseVisualStyleBackColor = false;
            this.ConnectButton.Click += new System.EventHandler(this.ConnectButton_Click);
            // 
            // TeleBot
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(568, 502);
            this.Controls.Add(this.ConnectButton);
            this.Controls.Add(this.QuestionButton);
            this.Controls.Add(this.DownButton);
            this.Controls.Add(this.RightButton);
            this.Controls.Add(this.UpButton);
            this.Controls.Add(this.LeftButton);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            //this.FormClosing += Window_Closed;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.Name = "TeleBot";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.Text = "Student TeleBot";
            this.Load += new System.EventHandler(this.TeleBot_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button LeftButton;
        private System.Windows.Forms.Button UpButton;
        private System.Windows.Forms.Button RightButton;
        private System.Windows.Forms.Button DownButton;
        private System.Windows.Forms.Button QuestionButton;
        private System.Windows.Forms.Button ConnectButton;
    }
}

