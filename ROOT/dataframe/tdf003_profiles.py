## \file
## \ingroup tutorial_tdataframe
## \notebook -nodraw
## This tutorial illustrates how to use TProfiles in combination with the
## TDataFrame. See the documentation of TProfile and TProfile2D to better
## understand the analogy of this code with the example one.
##
## \macro_code
##
## \date February 2017
## \author Danilo Piparo

import ROOT
TDataFrame = ROOT.ROOT.Experimental.TDataFrame

# A simple helper function to fill a test tree: this makes the example
# stand-alone.
def fill_tree(treeName, fileName):
    d = TDataFrame(25000)
    d.Define("px", "gRandom->Gaus()")\
     .Define("py", "gRandom->Gaus()")\
     .Define("pz", "sqrt(px * px + py * py)")\
     .Snapshot(treeName, fileName)



# We prepare an input tree to run on
fileName = "tdf003_profiles.root"
treeName = "myTree"
fill_tree(treeName, fileName)

# We read the tree from the file and create a TDataFrame.
columns = ROOT.vector('string')()
columns.push_back("px")
columns.push_back("py")
columns.push_back("pz")
d = TDataFrame(treeName, fileName, columns)

# Create the profiles
hprof1d = d.Profile1D(("hprof1d", "Profile of pz versus px", 64, -4, 4))
hprof2d = d.Profile2D(("hprof2d", "Profile of pz versus px and py", 40, -4, 4, 40, -4, 4, 0, 20))

# And Draw
c1 = ROOT.TCanvas("c1", "Profile histogram example", 200, 10, 700, 500)
hprof1d.Draw()
c2 = ROOT.TCanvas("c2", "Profile2D histogram example", 200, 10, 700, 500)
c2.cd()
hprof2d.Draw()

