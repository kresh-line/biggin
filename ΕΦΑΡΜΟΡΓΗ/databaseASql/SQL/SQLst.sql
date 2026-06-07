USE [tESTD]
GO

/****** Object:  Table [dbo].[studentet]    Script Date: 06-Jun-26 7:47:13 PM ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[studentet](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[emri] [nvarchar](100) NOT NULL,
	[email] [nchar](150) NULL,
	[mesatarja] [decimal](4, 2) NULL,
 CONSTRAINT [PK_studentet] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO


