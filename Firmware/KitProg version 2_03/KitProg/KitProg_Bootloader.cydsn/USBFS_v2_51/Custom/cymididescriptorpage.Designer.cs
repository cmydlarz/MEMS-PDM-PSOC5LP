namespace USBFS_v2_51
{
    partial class CyMidiDescriptorPage
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CyMidiDescriptorPage));
            System.Windows.Forms.ListViewGroup listViewGroup1 = new System.Windows.Forms.ListViewGroup("Audio Interfaces", System.Windows.Forms.HorizontalAlignment.Left);
            System.Windows.Forms.ListViewGroup listViewGroup2 = new System.Windows.Forms.ListViewGroup("Audio Control Descriptors (1.0)", System.Windows.Forms.HorizontalAlignment.Left);
            System.Windows.Forms.ListViewGroup listViewGroup3 = new System.Windows.Forms.ListViewGroup("Audio Control Descriptors (2.0)", System.Windows.Forms.HorizontalAlignment.Left);
            System.Windows.Forms.ListViewGroup listViewGroup4 = new System.Windows.Forms.ListViewGroup("MIDI Descriptors", System.Windows.Forms.HorizontalAlignment.Left);
            System.Windows.Forms.ListViewGroup listViewGroup5 = new System.Windows.Forms.ListViewGroup("Endpoint Descriptors", System.Windows.Forms.HorizontalAlignment.Left);
            this.splitContainerReport = new System.Windows.Forms.SplitContainer();
            this.treeViewMidi = new System.Windows.Forms.TreeView();
            this.imageList = new System.Windows.Forms.ImageList(this.components);
            this.panelCb = new System.Windows.Forms.Panel();
            this.checkBoxMode = new System.Windows.Forms.CheckBox();
            this.checkBoxEnableMIDIApi = new System.Windows.Forms.CheckBox();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripButtonRemove = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButtonImport = new System.Windows.Forms.ToolStripButton();
            this.toolStripButtonSave = new System.Windows.Forms.ToolStripButton();
            this.splitContainerDetails = new System.Windows.Forms.SplitContainer();
            this.listViewMidiDescList = new System.Windows.Forms.ListView();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.labelItemProperties = new System.Windows.Forms.Label();
            this.panelDetails = new System.Windows.Forms.Panel();
            this.panelAddbtn = new System.Windows.Forms.Panel();
            this.buttonApply = new System.Windows.Forms.Button();
            this.propertyGridMidi = new System.Windows.Forms.PropertyGrid();
            this.toolTipList = new System.Windows.Forms.ToolTip(this.components);
            this.splitContainerReport.Panel1.SuspendLayout();
            this.splitContainerReport.Panel2.SuspendLayout();
            this.splitContainerReport.SuspendLayout();
            this.panelCb.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.splitContainerDetails.Panel1.SuspendLayout();
            this.splitContainerDetails.Panel2.SuspendLayout();
            this.splitContainerDetails.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.panelDetails.SuspendLayout();
            this.panelAddbtn.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitContainerReport
            // 
            this.splitContainerReport.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.splitContainerReport.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainerReport.Location = new System.Drawing.Point(0, 0);
            this.splitContainerReport.Name = "splitContainerReport";
            // 
            // splitContainerReport.Panel1
            // 
            this.splitContainerReport.Panel1.Controls.Add(this.treeViewMidi);
            this.splitContainerReport.Panel1.Controls.Add(this.panelCb);
            this.splitContainerReport.Panel1.Controls.Add(this.toolStrip1);
            // 
            // splitContainerReport.Panel2
            // 
            this.splitContainerReport.Panel2.Controls.Add(this.splitContainerDetails);
            this.splitContainerReport.Size = new System.Drawing.Size(600, 363);
            this.splitContainerReport.SplitterDistance = 240;
            this.splitContainerReport.TabIndex = 0;
            // 
            // treeViewMidi
            // 
            this.treeViewMidi.AllowDrop = true;
            this.treeViewMidi.Dock = System.Windows.Forms.DockStyle.Fill;
            this.treeViewMidi.HideSelection = false;
            this.treeViewMidi.ImageIndex = 0;
            this.treeViewMidi.ImageList = this.imageList;
            this.treeViewMidi.LabelEdit = true;
            this.treeViewMidi.Location = new System.Drawing.Point(0, 25);
            this.treeViewMidi.Name = "treeViewMidi";
            this.treeViewMidi.SelectedImageIndex = 0;
            this.treeViewMidi.Size = new System.Drawing.Size(236, 283);
            this.treeViewMidi.TabIndex = 2;
            this.treeViewMidi.BeforeLabelEdit += new System.Windows.Forms.NodeLabelEditEventHandler(this.treeViewMidi_BeforeLabelEdit);
            this.treeViewMidi.AfterLabelEdit += new System.Windows.Forms.NodeLabelEditEventHandler(this.treeViewMidi_AfterLabelEdit);
            this.treeViewMidi.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.treeViewMidi_ItemDrag);
            this.treeViewMidi.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeViewMidi_AfterSelect);
            this.treeViewMidi.DragDrop += new System.Windows.Forms.DragEventHandler(this.treeViewMidi_DragDrop);
            this.treeViewMidi.DragEnter += new System.Windows.Forms.DragEventHandler(this.treeViewMidi_DragEnter);
            this.treeViewMidi.DragOver += new System.Windows.Forms.DragEventHandler(this.treeViewMidi_DragOver);
            this.treeViewMidi.DragLeave += new System.EventHandler(this.treeViewMidi_DragLeave);
            this.treeViewMidi.Enter += new System.EventHandler(this.treeViewMidi_Enter);
            this.treeViewMidi.KeyDown += new System.Windows.Forms.KeyEventHandler(this.treeViewMidi_KeyDown);
            // 
            // imageList
            // 
            this.imageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList.ImageStream")));
            this.imageList.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList.Images.SetKeyName(0, "Folder.png");
            this.imageList.Images.SetKeyName(1, "USB Drive.png");
            this.imageList.Images.SetKeyName(2, "Configuration.png");
            this.imageList.Images.SetKeyName(3, "Script.png");
            this.imageList.Images.SetKeyName(4, "Save.png");
            this.imageList.Images.SetKeyName(5, "Component.png");
            this.imageList.Images.SetKeyName(6, "AudioHS.png");
            // 
            // panelCb
            // 
            this.panelCb.Controls.Add(this.checkBoxMode);
            this.panelCb.Controls.Add(this.checkBoxEnableMIDIApi);
            this.panelCb.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panelCb.Location = new System.Drawing.Point(0, 308);
            this.panelCb.Name = "panelCb";
            this.panelCb.Size = new System.Drawing.Size(236, 51);
            this.panelCb.TabIndex = 4;
            // 
            // checkBoxMode
            // 
            this.checkBoxMode.AutoSize = true;
            this.checkBoxMode.Location = new System.Drawing.Point(16, 29);
            this.checkBoxMode.Name = "checkBoxMode";
            this.checkBoxMode.Size = new System.Drawing.Size(94, 17);
            this.checkBoxMode.TabIndex = 1;
            this.checkBoxMode.Text = "External Mode";
            this.checkBoxMode.UseVisualStyleBackColor = true;
            this.checkBoxMode.CheckedChanged += new System.EventHandler(this.checkBoxMode_CheckedChanged);
            // 
            // checkBoxEnableMIDIApi
            // 
            this.checkBoxEnableMIDIApi.AutoSize = true;
            this.checkBoxEnableMIDIApi.Location = new System.Drawing.Point(16, 6);
            this.checkBoxEnableMIDIApi.Name = "checkBoxEnableMIDIApi";
            this.checkBoxEnableMIDIApi.Size = new System.Drawing.Size(133, 17);
            this.checkBoxEnableMIDIApi.TabIndex = 0;
            this.checkBoxEnableMIDIApi.Text = "Enable MIDI Class API";
            this.checkBoxEnableMIDIApi.UseVisualStyleBackColor = true;
            this.checkBoxEnableMIDIApi.CheckedChanged += new System.EventHandler(this.checkBoxEnableMIDIApi_CheckedChanged);
            // 
            // toolStrip1
            // 
            this.toolStrip1.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButtonRemove,
            this.toolStripSeparator1,
            this.toolStripButtonImport,
            this.toolStripButtonSave});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(236, 25);
            this.toolStrip1.TabIndex = 1;
            this.toolStrip1.Text = "toolStrip";
            // 
            // toolStripButtonRemove
            // 
            this.toolStripButtonRemove.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonRemove.Enabled = false;
            this.toolStripButtonRemove.Image = global::USBFS_v2_51.Properties.Resources.imdelete;
            this.toolStripButtonRemove.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonRemove.Name = "toolStripButtonRemove";
            this.toolStripButtonRemove.Size = new System.Drawing.Size(23, 22);
            this.toolStripButtonRemove.Text = "Delete";
            this.toolStripButtonRemove.Click += new System.EventHandler(this.toolStripButtonRemove_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // toolStripButtonImport
            // 
            this.toolStripButtonImport.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonImport.Image = global::USBFS_v2_51.Properties.Resources.imimport;
            this.toolStripButtonImport.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonImport.Name = "toolStripButtonImport";
            this.toolStripButtonImport.Size = new System.Drawing.Size(23, 22);
            this.toolStripButtonImport.Text = "Import MIDI Interface";
            this.toolStripButtonImport.Click += new System.EventHandler(this.toolStripButtonImport_Click);
            // 
            // toolStripButtonSave
            // 
            this.toolStripButtonSave.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButtonSave.Image = global::USBFS_v2_51.Properties.Resources.imsave;
            this.toolStripButtonSave.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButtonSave.Name = "toolStripButtonSave";
            this.toolStripButtonSave.Size = new System.Drawing.Size(23, 22);
            this.toolStripButtonSave.Text = "Save MIDI Interface";
            this.toolStripButtonSave.Click += new System.EventHandler(this.toolStripButtonSave_Click);
            // 
            // splitContainerDetails
            // 
            this.splitContainerDetails.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.splitContainerDetails.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainerDetails.Location = new System.Drawing.Point(0, 0);
            this.splitContainerDetails.Name = "splitContainerDetails";
            this.splitContainerDetails.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainerDetails.Panel1
            // 
            this.splitContainerDetails.Panel1.BackColor = System.Drawing.Color.LightSteelBlue;
            this.splitContainerDetails.Panel1.Controls.Add(this.listViewMidiDescList);
            this.splitContainerDetails.Panel1.Controls.Add(this.pictureBox1);
            this.splitContainerDetails.Panel1.Controls.Add(this.label1);
            // 
            // splitContainerDetails.Panel2
            // 
            this.splitContainerDetails.Panel2.BackColor = System.Drawing.Color.LightSteelBlue;
            this.splitContainerDetails.Panel2.Controls.Add(this.labelItemProperties);
            this.splitContainerDetails.Panel2.Controls.Add(this.panelDetails);
            this.splitContainerDetails.Size = new System.Drawing.Size(356, 363);
            this.splitContainerDetails.SplitterDistance = 155;
            this.splitContainerDetails.TabIndex = 0;
            // 
            // listViewMidiDescList
            // 
            this.listViewMidiDescList.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            listViewGroup1.Header = "Audio Interfaces";
            listViewGroup1.Name = "groupInterface";
            listViewGroup2.Header = "Audio Control Descriptors (1.0)";
            listViewGroup2.Name = "groupAC";
            listViewGroup3.Header = "Audio Control Descriptors (2.0)";
            listViewGroup3.Name = "groupAC2";
            listViewGroup4.Header = "MIDI Descriptors";
            listViewGroup4.Name = "groupMS";
            listViewGroup5.Header = "Endpoint Descriptors";
            listViewGroup5.Name = "groupEndpoint";
            this.listViewMidiDescList.Groups.AddRange(new System.Windows.Forms.ListViewGroup[] {
            listViewGroup1,
            listViewGroup2,
            listViewGroup3,
            listViewGroup4,
            listViewGroup5});
            this.listViewMidiDescList.LargeImageList = this.imageList;
            this.listViewMidiDescList.Location = new System.Drawing.Point(2, 28);
            this.listViewMidiDescList.MultiSelect = false;
            this.listViewMidiDescList.Name = "listViewMidiDescList";
            this.listViewMidiDescList.Size = new System.Drawing.Size(347, 120);
            this.listViewMidiDescList.TabIndex = 11;
            this.listViewMidiDescList.UseCompatibleStateImageBehavior = false;
            this.listViewMidiDescList.SelectedIndexChanged += new System.EventHandler(this.listViewMidiDescList_SelectedIndexChanged);
            this.listViewMidiDescList.DoubleClick += new System.EventHandler(this.listViewMidiDescList_DoubleClick);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::USBFS_v2_51.Properties.Resources.imcomponentadd;
            this.pictureBox1.Location = new System.Drawing.Point(6, 6);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(16, 16);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pictureBox1.TabIndex = 10;
            this.pictureBox1.TabStop = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Tahoma", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.ForeColor = System.Drawing.SystemColors.ControlText;
            this.label1.Location = new System.Drawing.Point(28, 6);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(162, 16);
            this.label1.TabIndex = 8;
            this.label1.Text = "Audio/MIDI Descriptors List";
            // 
            // labelItemProperties
            // 
            this.labelItemProperties.AutoSize = true;
            this.labelItemProperties.Font = new System.Drawing.Font("Tahoma", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelItemProperties.ForeColor = System.Drawing.SystemColors.ControlText;
            this.labelItemProperties.Location = new System.Drawing.Point(2, 3);
            this.labelItemProperties.Name = "labelItemProperties";
            this.labelItemProperties.Size = new System.Drawing.Size(128, 16);
            this.labelItemProperties.TabIndex = 9;
            this.labelItemProperties.Text = "Descriptor Properties";
            // 
            // panelDetails
            // 
            this.panelDetails.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.panelDetails.BackColor = System.Drawing.Color.Transparent;
            this.panelDetails.Controls.Add(this.panelAddbtn);
            this.panelDetails.Controls.Add(this.propertyGridMidi);
            this.panelDetails.Location = new System.Drawing.Point(2, 22);
            this.panelDetails.Name = "panelDetails";
            this.panelDetails.Size = new System.Drawing.Size(347, 176);
            this.panelDetails.TabIndex = 1;
            // 
            // panelAddbtn
            // 
            this.panelAddbtn.BackColor = System.Drawing.SystemColors.Control;
            this.panelAddbtn.Controls.Add(this.buttonApply);
            this.panelAddbtn.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panelAddbtn.Location = new System.Drawing.Point(0, 145);
            this.panelAddbtn.Name = "panelAddbtn";
            this.panelAddbtn.Size = new System.Drawing.Size(347, 31);
            this.panelAddbtn.TabIndex = 1;
            // 
            // buttonApply
            // 
            this.buttonApply.Location = new System.Drawing.Point(4, 3);
            this.buttonApply.Name = "buttonApply";
            this.buttonApply.Size = new System.Drawing.Size(99, 25);
            this.buttonApply.TabIndex = 8;
            this.buttonApply.Text = "Add";
            this.buttonApply.UseVisualStyleBackColor = true;
            this.buttonApply.Click += new System.EventHandler(this.buttonApply_Click);
            // 
            // propertyGridMidi
            // 
            this.propertyGridMidi.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.propertyGridMidi.HelpVisible = false;
            this.propertyGridMidi.Location = new System.Drawing.Point(0, 0);
            this.propertyGridMidi.Name = "propertyGridMidi";
            this.propertyGridMidi.PropertySort = System.Windows.Forms.PropertySort.Categorized;
            this.propertyGridMidi.Size = new System.Drawing.Size(347, 139);
            this.propertyGridMidi.TabIndex = 0;
            this.propertyGridMidi.ToolbarVisible = false;
            this.propertyGridMidi.PropertyValueChanged += new System.Windows.Forms.PropertyValueChangedEventHandler(this.propertyGridMidi_PropertyValueChanged);
            // 
            // CyMidiDescriptorPage
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.splitContainerReport);
            this.Name = "CyMidiDescriptorPage";
            this.Size = new System.Drawing.Size(600, 363);
            this.VisibleChanged += new System.EventHandler(this.CyMidiDescriptorPage_VisibleChanged);
            this.splitContainerReport.Panel1.ResumeLayout(false);
            this.splitContainerReport.Panel1.PerformLayout();
            this.splitContainerReport.Panel2.ResumeLayout(false);
            this.splitContainerReport.ResumeLayout(false);
            this.panelCb.ResumeLayout(false);
            this.panelCb.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.splitContainerDetails.Panel1.ResumeLayout(false);
            this.splitContainerDetails.Panel1.PerformLayout();
            this.splitContainerDetails.Panel2.ResumeLayout(false);
            this.splitContainerDetails.Panel2.PerformLayout();
            this.splitContainerDetails.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.panelDetails.ResumeLayout(false);
            this.panelAddbtn.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainerReport;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.SplitContainer splitContainerDetails;
        private System.Windows.Forms.ImageList imageList;
        private System.Windows.Forms.TreeView treeViewMidi;
        private System.Windows.Forms.Panel panelDetails;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ToolStripButton toolStripButtonRemove;
        private System.Windows.Forms.Label labelItemProperties;
        private System.Windows.Forms.ToolTip toolTipList;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PropertyGrid propertyGridMidi;
        private System.Windows.Forms.ListView listViewMidiDescList;
        private System.Windows.Forms.Panel panelAddbtn;
        private System.Windows.Forms.Button buttonApply;
        private System.Windows.Forms.ToolStripButton toolStripButtonImport;
        private System.Windows.Forms.ToolStripButton toolStripButtonSave;
        private System.Windows.Forms.Panel panelCb;
        private System.Windows.Forms.CheckBox checkBoxEnableMIDIApi;
        private System.Windows.Forms.CheckBox checkBoxMode;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
    }
}
