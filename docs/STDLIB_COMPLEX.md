# Bibliothèques complexes AFRILANG

**710 modules** — `std/c/{nom}`

## std/c/graphbfs

`import "std/c/graphbfs"` · `use graphbfs`

- `bfsDistances(adj list number, n number, start number) → list number`
- `bfsOrder(adj list number, n number, start number) → list number`
- `bfsReachable(adj list number, n number, start number) → number`
- `bfsLayers(adj list number, n number, start number) → list number`
- `isConnected(adj list number, n number) → bool`
- `shortestPathLen(adj list number, n number, start number, goal number) → number`
- `multiSourceBfs(adj list number, n number, sources list number) → list number`

## std/c/graphdfs

`import "std/c/graphdfs"` · `use graphdfs`

- `dfsOrder(adj list number, n number, start number) → list number`
- `dfsRecursiveMark(adj list number, n number) → list number`
- `hasCycleUndirected(adj list number, n number) → bool`
- `countComponents(adj list number, n number) → number`
- `topoSortDfs(adj list number, n number) → list number`
- `isTree(adj list number, n number) → bool`
- `dfsPathExists(adj list number, n number, start number, goal number) → bool`

## std/c/graphdijk

`import "std/c/graphdijk"` · `use graphdijk`

- `dijkstra(adj list number, n number, start number) → list number`
- `shortestWeighted(adj list number, n number, start number, goal number) → number`
- `dijkstraPath(adj list number, n number, start number, goal number) → list number`
- `minEdgeWeight(adj list number, n number) → number`
- `maxEdgeWeight(adj list number, n number) → number`
- `avgEdgeWeight(adj list number, n number) → number`
- `edgeCount(adj list number, n number) → number`

## std/c/graphtopo

`import "std/c/graphtopo"` · `use graphtopo`

- `topoSort(adj list number, n number) → list number`
- `hasCycleDirected(adj list number, n number) → bool`
- `inDegrees(adj list number, n number) → list number`
- `outDegrees(adj list number, n number) → list number`
- `sources(adj list number, n number) → list number`
- `sinks(adj list number, n number) → list number`
- `isDag(adj list number, n number) → bool`

## std/c/graphcc

`import "std/c/graphcc"` · `use graphcc`

- `connectedComponents(adj list number, n number) → list number`
- `componentCount(adj list number, n number) → number`
- `largestComponentSize(adj list number, n number) → number`
- `sameComponent(adj list number, n number, a number, b number) → bool`
- `componentSizes(adj list number, n number) → list number`
- `outDegreeSum(adj list number, n number) → list number`
- `isolateCount(adj list number, n number) → number`

## std/c/graphcycle

`import "std/c/graphcycle"` · `use graphcycle`

- `detectCycleDirected(adj list number, n number) → bool`
- `detectCycleUndirected(adj list number, n number) → bool`
- `cycleEdgeCount(adj list number, n number) → number`
- `isAcyclic(adj list number, n number) → bool`
- `selfLoopCount(adj list number, n number) → number`
- `removeSelfLoops(adj list number, n number) → list number`
- `hasParallelEdges(adj list number, n number) → bool`

## std/c/graphmst

`import "std/c/graphmst"` · `use graphmst`

- `mstWeightPrim(adj list number, n number) → number`
- `mstWeightKruskal(adj list number, n number) → number`
- `mstEdges(adj list number, n number) → number`
- `compareMstAlgos(adj list number, n number) → number`
- `forestMstWeight(adj list number, n number) → number`
- `isConnectedForMst(adj list number, n number) → bool`

## std/c/graphshort

`import "std/c/graphshort"` · `use graphshort`

- `allPairsBfs(adj list number, n number) → list number`
- `eccentricity(adj list number, n number) → list number`
- `graphDiameter(adj list number, n number) → number`
- `graphRadius(adj list number, n number) → number`
- `centerNodes(adj list number, n number) → list number`
- `peripheryNodes(adj list number, n number) → list number`

## std/c/graphbellman

`import "std/c/graphbellman"` · `use graphbellman`

- `bellmanFord(adj list number, n number, start number) → list number`
- `hasNegCycle(adj list number, n number) → bool`
- `negEdgeCount(adj list number, n number) → number`
- `relaxOnce(adj list number, n number, dist list number) → list number`
- `pathCost(adj list number, n number, path list number) → number`
- `reachableWeighted(adj list number, n number, start number) → number`

## std/c/graphfloyd

`import "std/c/graphfloyd"` · `use graphfloyd`

- `floydWarshall(adj list number, n number) → list number`
- `pairDistance(adj list number, n number, a number, b number) → number`
- `closureReachable(adj list number, n number) → list number`
- `graphDensity(adj list number, n number) → number`
- `avgShortestPath(adj list number, n number) → number`
- `transitiveClosure(adj list number, n number) → list number`

## std/c/graphprim

`import "std/c/graphprim"` · `use graphprim`

- `primMst(adj list number, n number) → number`
- `primParents(adj list number, n number) → list number`
- `primOrder(adj list number, n number) → list number`
- `mstEdgeCount(adj list number, n number) → number`
- `lightestEdge(adj list number, n number) → number`
- `heaviestMstEdge(adj list number, n number) → number`
- `isPrimConnected(adj list number, n number) → bool`

## std/c/graphkruskal

`import "std/c/graphkruskal"` · `use graphkruskal`

- `kruskalMst(adj list number, n number) → number`
- `kruskalEdges(adj list number, n number) → list number`
- `unionFindComponents(adj list number, n number) → number`
- `edgeListSize(adj list number, n number) → number`
- `kruskalForestWeight(adj list number, n number) → number`
- `maxSpanningForest(adj list number, n number) → number`
- `compareKruskalPrim(adj list number, n number) → number`

## std/c/graphbipart

`import "std/c/graphbipart"` · `use graphbipart`

- `isBipartite(adj list number, n number) → bool`
- `bipartiteColors(adj list number, n number) → list number`
- `partitionSizes(adj list number, n number) → list number`
- `crossEdgeCount(adj list number, n number) → number`
- `sameSideEdges(adj list number, n number) → number`
- `bipartiteDensity(adj list number, n number) → number`
- `hasOddCycle(adj list number, n number) → bool`

## std/c/grapheuler

`import "std/c/grapheuler"` · `use grapheuler`

- `vertexDegrees(adj list number, n number) → list number`
- `hasEulerCircuit(adj list number, n number) → bool`
- `hasEulerPath(adj list number, n number) → bool`
- `oddDegreeCount(adj list number, n number) → number`
- `totalDegree(adj list number, n number) → number`
- `eulerTrailLen(adj list number, n number) → number`
- `isEulerian(adj list number, n number) → bool`

## std/c/graphham

`import "std/c/graphham"` · `use graphham`

- `hamiltonianExists(adj list number, n number) → bool`
- `permuteCheck(adj list number, n number) → number`
- `longestPath(adj list number, n number) → number`
- `hamiltonianCycle(adj list number, n number) → bool`
- `pathCoverSize(adj list number, n number) → number`
- `tspLowerBound(adj list number, n number) → number`
- `nearestNeighbor(adj list number, n number, start number) → list number`

## std/c/graphclique

`import "std/c/graphclique"` · `use graphclique`

- `maxCliqueSize(adj list number, n number) → number`
- `cliqueNumber(adj list number, n number) → number`
- `isClique(adj list number, n number, nodes list number) → bool`
- `cliqueCover(adj list number, n number) → number`
- `triangleCount(adj list number, n number) → number`
- `clusteringCoeff(adj list number, n number) → list number`
- `density(adj list number, n number) → number`

## std/c/graphcolor

`import "std/c/graphcolor"` · `use graphcolor`

- `greedyColor(adj list number, n number) → list number`
- `chromaticNumber(adj list number, n number) → number`
- `isValidColoring(adj list number, n number, colors list number) → bool`
- `colorClasses(adj list number, n number) → list number`
- `conflictCount(adj list number, n number, colors list number) → number`
- `welshPowell(adj list number, n number) → list number`
- `sameColorNeighbors(adj list number, n number, node number) → number`

## std/c/graphflow

`import "std/c/graphflow"` · `use graphflow`

- `maxFlow(adj list number, n number, source number, sink number) → number`
- `minCutValue(adj list number, n number, source number, sink number) → number`
- `flowMatrix(adj list number, n number, source number, sink number) → list number`
- `bottleneckCapacity(adj list number, n number) → number`
- `outFlowSum(adj list number, n number, node number) → number`
- `inFlowSum(adj list number, n number, node number) → number`
- `isFlowConserved(adj list number, n number, source number, sink number) → bool`

## std/c/graphmatch

`import "std/c/graphmatch"` · `use graphmatch`

- `maxMatching(adj list number, n number) → number`
- `matchingPairs(adj list number, n number) → list number`
- `isPerfectMatching(adj list number, n number) → bool`
- `unmatchedCount(adj list number, n number) → number`
- `matchingWeight(adj list number, n number) → number`
- `vertexCoverSize(adj list number, n number) → number`
- `isMatched(adj list number, n number, node number) → bool`

## std/c/graphcent

`import "std/c/graphcent"` · `use graphcent`

- `degreeCentrality(adj list number, n number) → list number`
- `closenessCentrality(adj list number, n number) → list number`
- `betweennessApprox(adj list number, n number) → list number`
- `eigenvectorCentrality(adj list number, n number) → list number`
- `pageRank(adj list number, n number, damping number) → list number`
- `hubScore(adj list number, n number) → list number`
- `mostCentral(adj list number, n number) → number`

## std/c/statregress

`import "std/c/statregress"` · `use statregress`

- `regSum(v list number) → number`
- `regMean(v list number) → number`
- `regMin(v list number) → number`
- `regMax(v list number) → number`
- `regVar(v list number) → number`
- `regStd(v list number) → number`
- `regNorm(v list number) → list number`
- `linearRegress(x list number, y list number) → list number`

## std/c/statcorrel

`import "std/c/statcorrel"` · `use statcorrel`

- `pearson(a list number, b list number) → number`
- `covariance(a list number, b list number) → number`
- `crossCorr(a list number, b list number, lag number) → number`
- `autocorr1(v list number) → number`
- `partialCorr(a list number, b list number, c list number) → number`
- `corrMatrix2(a list number, b list number) → list number`
- `rankCorr(a list number, b list number) → number`

## std/c/statquartile

`import "std/c/statquartile"` · `use statquartile`

- `q1(v list number) → number`
- `q2(v list number) → number`
- `q3(v list number) → number`
- `iqr(v list number) → number`
- `quartiles(v list number) → list number`
- `fiveNum(v list number) → list number`
- `outlierFence(v list number) → list number`

## std/c/stathistogram

`import "std/c/stathistogram"` · `use stathistogram`

- `histogram(v list number, bins number) → list number`
- `binEdges(v list number, bins number) → list number`
- `freqDensity(v list number, bins number) → list number`
- `cumFreq(v list number, bins number) → list number`
- `modeBin(v list number, bins number) → number`
- `binWidth(v list number, bins number) → number`

## std/c/statanova

`import "std/c/statanova"` · `use statanova`

- `groupMeans(groups list number, labels list number) → list number`
- `grandMean(v list number) → number`
- `betweenSS(groups list number, labels list number) → number`
- `withinSS(groups list number, labels list number) → number`
- `fStatistic(groups list number, labels list number) → number`
- `etaSquared(groups list number, labels list number) → number`

## std/c/statttest

`import "std/c/statttest"` · `use statttest`

- `tStatistic(a list number, b list number) → number`
- `pooledVariance(a list number, b list number) → number`
- `cohenD(a list number, b list number) → number`
- `meanDiff(a list number, b list number) → number`
- `welchT(a list number, b list number) → number`
- `effectSize(a list number, b list number) → number`

## std/c/statchi2

`import "std/c/statchi2"` · `use statchi2`

- `chi2Stat(observed list number, expected list number) → number`
- `cramersV(chi2 number, n number, k number) → number`
- `expectedUniform(total number, bins number) → list number`
- `goodnessOfFit(observed list number, expected list number) → number`
- `residuals(observed list number, expected list number) → list number`
- `df(bins number) → number`

## std/c/statnormcdf

`import "std/c/statnormcdf"` · `use statnormcdf`

- `normPdf(x number, mu number, sigma number) → number`
- `normCdfApprox(x number, mu number, sigma number) → number`
- `zFromP(p number) → number`
- `standardize(x number, mu number, sigma number) → number`
- `logLikelihood(data list number, mu number, sigma number) → number`
- `bivariatePdf(x number, y number, rho number) → number`

## std/c/statzscore

`import "std/c/statzscore"` · `use statzscore`

- `zScores(v list number) → list number`
- `zScore(v list number, val number) → number`
- `isOutlierZ(v list number, val number, threshold number) → bool`
- `standardize(v list number) → list number`
- `destandardize(z list number, mean number, stddev number) → list number`
- `zMean(v list number) → number`

## std/c/statcovar

`import "std/c/statcovar"` · `use statcovar`

- `covSum(v list number) → number`
- `covMean(v list number) → number`
- `covMin(v list number) → number`
- `covMax(v list number) → number`
- `covVar(v list number) → number`
- `covStd(v list number) → number`
- `covNorm(v list number) → list number`
- `covariance(a list number, b list number) → number`

## std/c/statrmse

`import "std/c/statrmse"` · `use statrmse`

- `rmse(actual list number, predicted list number) → number`
- `mse(actual list number, predicted list number) → number`
- `mae(actual list number, predicted list number) → number`
- `nrmse(actual list number, predicted list number) → number`
- `smape(actual list number, predicted list number) → number`
- `r2Score(actual list number, predicted list number) → number`

## std/c/statmape

`import "std/c/statmape"` · `use statmape`

- `mape(actual list number, predicted list number) → number`
- `wape(actual list number, predicted list number) → number`
- `smape(actual list number, predicted list number) → number`
- `bias(actual list number, predicted list number) → number`
- `trackingSignal(actual list number, predicted list number) → number`
- `forecastError(actual list number, predicted list number) → list number`

## std/c/statmedian

`import "std/c/statmedian"` · `use statmedian`

- `median(v list number) → number`
- `medAbsDev(v list number) → number`
- `trimmedMean(v list number, pct number) → number`
- `movingMedian(v list number, win number) → list number`
- `weightedMedian(v list number, w list number) → number`
- `medianDiff(a list number, b list number) → number`

## std/c/statmode

`import "std/c/statmode"` · `use statmode`

- `mode(v list number) → number`
- `modeCount(v list number) → number`
- `multimodal(v list number) → bool`
- `uniqueCount(v list number) → number`
- `entropy(v list number) → number`
- `giniSimpson(v list number) → number`

## std/c/statskew

`import "std/c/statskew"` · `use statskew`

- `skewness(v list number) → number`
- `kurtosisExcess(v list number) → number`
- `moment3(v list number) → number`
- `moment4(v list number) → number`
- `jarqueBera(v list number) → number`
- `isSymmetric(v list number) → bool`

## std/c/statkurt

`import "std/c/statkurt"` · `use statkurt`

- `kurtosis(v list number) → number`
- `excessKurtosis(v list number) → number`
- `isLeptokurtic(v list number) → bool`
- `isPlatykurtic(v list number) → bool`
- `tailRatio(v list number) → number`
- `peakedness(v list number) → number`

## std/c/statbootstrap

`import "std/c/statbootstrap"` · `use statbootstrap`

- `bootstrapMean(v list number, samples number) → number`
- `bootstrapSE(v list number, samples number) → number`
- `resample(v list number, size number) → list number`
- `bootstrapCI(v list number, samples number) → list number`
- `jackknife(v list number) → list number`
- `biasCorrected(v list number, stat number) → number`

## std/c/statoutlier

`import "std/c/statoutlier"` · `use statoutlier`

- `iqrOutliers(v list number) → list number`
- `zOutliers(v list number, threshold number) → list number`
- `outlierCount(v list number) → number`
- `winsorize(v list number, pct number) → list number`
- `modifiedZ(v list number) → list number`
- `isOutlier(v list number, val number) → bool`

## std/c/statpercentile

`import "std/c/statpercentile"` · `use statpercentile`

- `percentile(v list number, p number) → number`
- `percentiles(v list number) → list number`
- `rankPct(v list number, val number) → number`
- `decile(v list number, d number) → number`
- `quantile(v list number, q number) → number`
- `p90(v list number) → number`
- `p99(v list number) → number`

## std/c/statbayes

`import "std/c/statbayes"` · `use statbayes`

- `bayesUpdate(prior number, likelihood number, evidence number) → number`
- `posteriorOdds(priorOdds number, likelihoodRatio number) → number`
- `priorFromOdds(odds number) → number`
- `oddsFromPrior(prior number) → number`
- `bayesFactor(likelihoodH1 number, likelihoodH0 number) → number`
- `credibleInterval(samples list number) → list number`
- `expectedLoss(losses list number, probs list number) → number`

## std/c/mlkmeans

`import "std/c/mlkmeans"` · `use mlkmeans`

- `kmeans(points list number, k number, dims number) → list number`
- `assignClusters(points list number, centroids list number, dims number) → list number`
- `inertia(points list number, centroids list number, dims number) → number`
- `clusterSizes(labels list number, k number) → list number`
- `silhouetteSample(points list number, labels list number, idx number, dims number) → number`
- `elbowK(points list number, maxK number, dims number) → number`

## std/c/mllinear

`import "std/c/mllinear"` · `use mllinear`

- `dot(a list number, b list number) → number`
- `predict(weights list number, features list number, bias number) → number`
- `mse(weights list number, X list number, y list number, dims number) → number`
- `gradientStep(weights list number, X list number, y list number, lr number, dims number) → list number`
- `trainEpochs(weights list number, X list number, y list number, lr number, epochs number, dims number) → list number`
- `sigmoid(x number) → number`

## std/c/mlnaivebayes

`import "std/c/mlnaivebayes"` · `use mlnaivebayes`

- `classPrior(labels list number, cls number) → number`
- `featureMean(features list number, labels list number, cls number, feat number) → number`
- `featureVar(features list number, labels list number, cls number) → number`
- `gaussianLikelihood(x number, mu number, sigma number) → number`
- `predictClass(features list number, trainX list number, trainY list number, numClasses number) → number`
- `logPosterior(features list number, trainX list number, trainY list number, cls number) → number`

## std/c/mltfidf

`import "std/c/mltfidf"` · `use mltfidf`

- `tfidSum(v list number) → number`
- `tfidMean(v list number) → number`
- `tfidMin(v list number) → number`
- `tfidMax(v list number) → number`
- `tfidVar(v list number) → number`
- `tfidStd(v list number) → number`
- `tfidNorm(v list number) → list number`

## std/c/mlcosine

`import "std/c/mlcosine"` · `use mlcosine`

- `cosineSim(a list number, b list number) → number`
- `cosineDist(a list number, b list number) → number`
- `normalize(v list number) → list number`
- `angularDist(a list number, b list number) → number`
- `batchCosine(query list number, matrix list number, dims number) → list number`
- `mostSimilar(query list number, matrix list number, dims number) → number`

## std/c/mlsvm

`import "std/c/mlsvm"` · `use mlsvm`

- `svmSum(v list number) → number`
- `svmMean(v list number) → number`
- `svmMin(v list number) → number`
- `svmMax(v list number) → number`
- `svmVar(v list number) → number`
- `svmStd(v list number) → number`
- `svmNorm(v list number) → list number`

## std/c/mlpca

`import "std/c/mlpca"` · `use mlpca`

- `pcaSum(v list number) → number`
- `pcaMean(v list number) → number`
- `pcaMin(v list number) → number`
- `pcaMax(v list number) → number`
- `pcaVar(v list number) → number`
- `pcaStd(v list number) → number`
- `pcaNorm(v list number) → list number`

## std/c/mlentropy

`import "std/c/mlentropy"` · `use mlentropy`

- `entrSum(v list number) → number`
- `entrMean(v list number) → number`
- `entrMin(v list number) → number`
- `entrMax(v list number) → number`
- `entrVar(v list number) → number`
- `entrStd(v list number) → number`
- `entrNorm(v list number) → list number`

## std/c/mlkldiv

`import "std/c/mlkldiv"` · `use mlkldiv`

- `kldiSum(v list number) → number`
- `kldiMean(v list number) → number`
- `kldiMin(v list number) → number`
- `kldiMax(v list number) → number`
- `kldiVar(v list number) → number`
- `kldiStd(v list number) → number`
- `kldiNorm(v list number) → list number`

## std/c/mlgradient

`import "std/c/mlgradient"` · `use mlgradient`

- `gradSum(v list number) → number`
- `gradMean(v list number) → number`
- `gradMin(v list number) → number`
- `gradMax(v list number) → number`
- `gradVar(v list number) → number`
- `gradStd(v list number) → number`
- `gradNorm(v list number) → list number`

## std/c/mlsoftmax

`import "std/c/mlsoftmax"` · `use mlsoftmax`

- `softmax(logits list number) → list number`
- `crossEntropy(probs list number, target number) → number`
- `argmax(v list number) → number`
- `oneHot(idx number, size number) → list number`
- `logSoftmax(logits list number) → list number`
- `entropy(probs list number) → number`

## std/c/mlperceptron

`import "std/c/mlperceptron"` · `use mlperceptron`

- `predict(weights list number, features list number, bias number) → number`
- `trainStep(weights list number, bias number, features list number, label number, lr number) → list number`
- `accuracy(weights list number, bias number, X list number, y list number, dims number) → number`
- `hingeLoss(weights list number, features list number, label number, bias number) → number`
- `initWeights(size number) → list number`
- `trainEpoch(weights list number, bias number, X list number, y list number, lr number, dims number) → list number`

## std/c/mlcrossval

`import "std/c/mlcrossval"` · `use mlcrossval`

- `crosSum(v list number) → number`
- `crosMean(v list number) → number`
- `crosMin(v list number) → number`
- `crosMax(v list number) → number`
- `crosVar(v list number) → number`
- `crosStd(v list number) → number`
- `crosNorm(v list number) → list number`

## std/c/mlfeature

`import "std/c/mlfeature"` · `use mlfeature`

- `featSum(v list number) → number`
- `featMean(v list number) → number`
- `featMin(v list number) → number`
- `featMax(v list number) → number`
- `featVar(v list number) → number`
- `featStd(v list number) → number`
- `featNorm(v list number) → list number`

## std/c/mlnormalize

`import "std/c/mlnormalize"` · `use mlnormalize`

- `normSum(v list number) → number`
- `normMean(v list number) → number`
- `normMin(v list number) → number`
- `normMax(v list number) → number`
- `normVar(v list number) → number`
- `normStd(v list number) → number`
- `normNorm(v list number) → list number`

## std/c/mldistance

`import "std/c/mldistance"` · `use mldistance`

- `distSum(v list number) → number`
- `distMean(v list number) → number`
- `distMin(v list number) → number`
- `distMax(v list number) → number`
- `distVar(v list number) → number`
- `distStd(v list number) → number`
- `distNorm(v list number) → list number`

## std/c/mlcluster

`import "std/c/mlcluster"` · `use mlcluster`

- `clusSum(v list number) → number`
- `clusMean(v list number) → number`
- `clusMin(v list number) → number`
- `clusMax(v list number) → number`
- `clusVar(v list number) → number`
- `clusStd(v list number) → number`
- `clusNorm(v list number) → list number`

## std/c/mlnearest

`import "std/c/mlnearest"` · `use mlnearest`

- `nearSum(v list number) → number`
- `nearMean(v list number) → number`
- `nearMin(v list number) → number`
- `nearMax(v list number) → number`
- `nearVar(v list number) → number`
- `nearStd(v list number) → number`
- `nearNorm(v list number) → list number`

## std/c/mldecision

`import "std/c/mldecision"` · `use mldecision`

- `deciSum(v list number) → number`
- `deciMean(v list number) → number`
- `deciMin(v list number) → number`
- `deciMax(v list number) → number`
- `deciVar(v list number) → number`
- `deciStd(v list number) → number`
- `deciNorm(v list number) → list number`

## std/c/mlensemble

`import "std/c/mlensemble"` · `use mlensemble`

- `enseSum(v list number) → number`
- `enseMean(v list number) → number`
- `enseMin(v list number) → number`
- `enseMax(v list number) → number`
- `enseVar(v list number) → number`
- `enseStd(v list number) → number`
- `enseNorm(v list number) → list number`

## std/c/cryptsha256

`import "std/c/cryptsha256"` · `use cryptsha256`

- `sha2Len(s text) → number`
- `sha2Upper(s text) → text`
- `sha2Lower(s text) → text`
- `sha2Trim(s text) → text`
- `sha2Split(s text, delim text) → list text`
- `sha2Join(parts list text, delim text) → text`
- `sha2Replace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptsha1

`import "std/c/cryptsha1"` · `use cryptsha1`

- `sha1Len(s text) → number`
- `sha1Upper(s text) → text`
- `sha1Lower(s text) → text`
- `sha1Trim(s text) → text`
- `sha1Split(s text, delim text) → list text`
- `sha1Join(parts list text, delim text) → text`
- `sha1Replace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptmd5

`import "std/c/cryptmd5"` · `use cryptmd5`

- `md5Len(s text) → number`
- `md5Upper(s text) → text`
- `md5Lower(s text) → text`
- `md5Trim(s text) → text`
- `md5Split(s text, delim text) → list text`
- `md5Join(parts list text, delim text) → text`
- `md5Replace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/crypthmac

`import "std/c/crypthmac"` · `use crypthmac`

- `hmacLen(s text) → number`
- `hmacUpper(s text) → text`
- `hmacLower(s text) → text`
- `hmacTrim(s text) → text`
- `hmacSplit(s text, delim text) → list text`
- `hmacJoin(parts list text, delim text) → text`
- `hmacReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptxor

`import "std/c/cryptxor"` · `use cryptxor`

- `xorBytes(a text, b text) → text`
- `xorHex(hex text, key text) → text`
- `repeatKey(data text, key text) → text`
- `xorList(a list number, b list number) → list number`
- `parity(s text) → number`
- `rollingXor(data list number, key number) → list number`
- `selfXor(s text) → text`

## std/c/cryptcaesar

`import "std/c/cryptcaesar"` · `use cryptcaesar`

- `encrypt(s text, shift number) → text`
- `decrypt(s text, shift number) → text`
- `bruteForce(s text) → list text`
- `countAlpha(s text) → number`
- `rotAll(s text) → list text`
- `isCaesar(plain text, cipher text) → bool`

## std/c/cryptvigenere

`import "std/c/cryptvigenere"` · `use cryptvigenere`

- `vigeLen(s text) → number`
- `vigeUpper(s text) → text`
- `vigeLower(s text) → text`
- `vigeTrim(s text) → text`
- `vigeSplit(s text, delim text) → list text`
- `vigeJoin(parts list text, delim text) → text`
- `vigeReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptbase64

`import "std/c/cryptbase64"` · `use cryptbase64`

- `encode(s text) → text`
- `decode(s text) → text`
- `isValid(s text) → bool`
- `paddedLen(s text) → number`
- `roundTrip(s text) → bool`
- `urlSafe(s text) → text`

## std/c/cryptrot13

`import "std/c/cryptrot13"` · `use cryptrot13`

- `rot1Len(s text) → number`
- `rot1Upper(s text) → text`
- `rot1Lower(s text) → text`
- `rot1Trim(s text) → text`
- `rot1Split(s text, delim text) → list text`
- `rot1Join(parts list text, delim text) → text`
- `rot1Replace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptaeslite

`import "std/c/cryptaeslite"` · `use cryptaeslite`

- `aeslLen(s text) → number`
- `aeslUpper(s text) → text`
- `aeslLower(s text) → text`
- `aeslTrim(s text) → text`
- `aeslSplit(s text, delim text) → list text`
- `aeslJoin(parts list text, delim text) → text`
- `aeslReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptpbkdf

`import "std/c/cryptpbkdf"` · `use cryptpbkdf`

- `pbkdLen(s text) → number`
- `pbkdUpper(s text) → text`
- `pbkdLower(s text) → text`
- `pbkdTrim(s text) → text`
- `pbkdSplit(s text, delim text) → list text`
- `pbkdJoin(parts list text, delim text) → text`
- `pbkdReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptscrypt

`import "std/c/cryptscrypt"` · `use cryptscrypt`

- `scryLen(s text) → number`
- `scryUpper(s text) → text`
- `scryLower(s text) → text`
- `scryTrim(s text) → text`
- `scrySplit(s text, delim text) → list text`
- `scryJoin(parts list text, delim text) → text`
- `scryReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptnonce

`import "std/c/cryptnonce"` · `use cryptnonce`

- `noncLen(s text) → number`
- `noncUpper(s text) → text`
- `noncLower(s text) → text`
- `noncTrim(s text) → text`
- `noncSplit(s text, delim text) → list text`
- `noncJoin(parts list text, delim text) → text`
- `noncReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptcrc32

`import "std/c/cryptcrc32"` · `use cryptcrc32`

- `crc32(s text) → number`
- `crc32List(data list number) → list number`
- `verify(s text, expected number) → bool`
- `update(crc number, byte number) → number`
- `finalize(crc number) → number`
- `chunkCrc(s text, chunkSize number) → list number`

## std/c/cryptparity

`import "std/c/cryptparity"` · `use cryptparity`

- `pariLen(s text) → number`
- `pariUpper(s text) → text`
- `pariLower(s text) → text`
- `pariTrim(s text) → text`
- `pariSplit(s text, delim text) → list text`
- `pariJoin(parts list text, delim text) → text`
- `pariReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/comprle

`import "std/c/comprle"` · `use comprle`

- `rleEncode(data list number) → list number`
- `rleDecode(encoded list number) → list number`
- `rleRatio(data list number) → number`
- `runLength(data list number) → number`
- `compress(data list number) → list number`
- `decompress(encoded list number) → list number`
- `isCompressible(data list number) → bool`

## std/c/compdelta

`import "std/c/compdelta"` · `use compdelta`

- `deltaEncode(data list number) → list number`
- `deltaDecode(encoded list number) → list number`
- `deltaSum(data list number) → number`
- `secondOrder(data list number) → list number`
- `roundTrip(data list number) → bool`
- `maxDelta(data list number) → number`

## std/c/compresshuff

`import "std/c/compresshuff"` · `use compresshuff`

- `resshuffEncode(data list number) → list number`
- `resshuffDecode(encoded list number) → list number`
- `resshuffRatio(data list number) → number`
- `resshuffSize(data list number) → number`
- `resshuffCompressed(data list number) → number`
- `resshuffRoundTrip(data list number) → bool`

## std/c/complz77

`import "std/c/complz77"` · `use complz77`

- `lz77Encode(data list number) → list number`
- `lz77Decode(encoded list number) → list number`
- `lz77Ratio(data list number) → number`
- `lz77Size(data list number) → number`
- `lz77Compressed(data list number) → number`
- `lz77RoundTrip(data list number) → bool`

## std/c/complzw

`import "std/c/complzw"` · `use complzw`

- `lzwEncode(data list number) → list number`
- `lzwDecode(encoded list number) → list number`
- `lzwRatio(data list number) → number`
- `lzwSize(data list number) → number`
- `lzwCompressed(data list number) → number`
- `lzwRoundTrip(data list number) → bool`

## std/c/comprunlen

`import "std/c/comprunlen"` · `use comprunlen`

- `runlenEncode(data list number) → list number`
- `runlenDecode(encoded list number) → list number`
- `runlenRatio(data list number) → number`
- `runlenSize(data list number) → number`
- `runlenCompressed(data list number) → number`
- `runlenRoundTrip(data list number) → bool`

## std/c/compbitpack

`import "std/c/compbitpack"` · `use compbitpack`

- `bitpackEncode(data list number) → list number`
- `bitpackDecode(encoded list number) → list number`
- `bitpackRatio(data list number) → number`
- `bitpackSize(data list number) → number`
- `bitpackCompressed(data list number) → number`
- `bitpackRoundTrip(data list number) → bool`

## std/c/compvarint

`import "std/c/compvarint"` · `use compvarint`

- `varintEncode(data list number) → list number`
- `varintDecode(encoded list number) → list number`
- `varintRatio(data list number) → number`
- `varintSize(data list number) → number`
- `varintCompressed(data list number) → number`
- `varintRoundTrip(data list number) → bool`

## std/c/compdict

`import "std/c/compdict"` · `use compdict`

- `dictEncode(data list number) → list number`
- `dictDecode(encoded list number) → list number`
- `dictRatio(data list number) → number`
- `dictSize(data list number) → number`
- `dictCompressed(data list number) → number`
- `dictRoundTrip(data list number) → bool`

## std/c/compframe

`import "std/c/compframe"` · `use compframe`

- `frameEncode(data list number) → list number`
- `frameDecode(encoded list number) → list number`
- `frameRatio(data list number) → number`
- `frameSize(data list number) → number`
- `frameCompressed(data list number) → number`
- `frameRoundTrip(data list number) → bool`

## std/c/parsejsonadv

`import "std/c/parsejsonadv"` · `use parsejsonadv`

- `jsonLen(s text) → number`
- `jsonUpper(s text) → text`
- `jsonLower(s text) → text`
- `jsonTrim(s text) → text`
- `jsonSplit(s text, delim text) → list text`
- `jsonJoin(parts list text, delim text) → text`
- `jsonReplace(s text, from text, to text) → text`

## std/c/parsexml

`import "std/c/parsexml"` · `use parsexml`

- `xmlLen(s text) → number`
- `xmlUpper(s text) → text`
- `xmlLower(s text) → text`
- `xmlTrim(s text) → text`
- `xmlSplit(s text, delim text) → list text`
- `xmlJoin(parts list text, delim text) → text`
- `xmlReplace(s text, from text, to text) → text`

## std/c/parseini

`import "std/c/parseini"` · `use parseini`

- `iniLen(s text) → number`
- `iniUpper(s text) → text`
- `iniLower(s text) → text`
- `iniTrim(s text) → text`
- `iniSplit(s text, delim text) → list text`
- `iniJoin(parts list text, delim text) → text`
- `iniReplace(s text, from text, to text) → text`

## std/c/parsetoml

`import "std/c/parsetoml"` · `use parsetoml`

- `tomlLen(s text) → number`
- `tomlUpper(s text) → text`
- `tomlLower(s text) → text`
- `tomlTrim(s text) → text`
- `tomlSplit(s text, delim text) → list text`
- `tomlJoin(parts list text, delim text) → text`
- `tomlReplace(s text, from text, to text) → text`

## std/c/parsepath

`import "std/c/parsepath"` · `use parsepath`

- `pathLen(s text) → number`
- `pathUpper(s text) → text`
- `pathLower(s text) → text`
- `pathTrim(s text) → text`
- `pathSplit(s text, delim text) → list text`
- `pathJoin(parts list text, delim text) → text`
- `pathReplace(s text, from text, to text) → text`

## std/c/parseyaml

`import "std/c/parseyaml"` · `use parseyaml`

- `yamlLen(s text) → number`
- `yamlUpper(s text) → text`
- `yamlLower(s text) → text`
- `yamlTrim(s text) → text`
- `yamlSplit(s text, delim text) → list text`
- `yamlJoin(parts list text, delim text) → text`
- `yamlReplace(s text, from text, to text) → text`

## std/c/parsecsvadv

`import "std/c/parsecsvadv"` · `use parsecsvadv`

- `csvLen(s text) → number`
- `csvUpper(s text) → text`
- `csvLower(s text) → text`
- `csvTrim(s text) → text`
- `csvSplit(s text, delim text) → list text`
- `csvJoin(parts list text, delim text) → text`
- `csvReplace(s text, from text, to text) → text`
- `parseRow(line text, delim text) → list text`

## std/c/parsehtml

`import "std/c/parsehtml"` · `use parsehtml`

- `htmlLen(s text) → number`
- `htmlUpper(s text) → text`
- `htmlLower(s text) → text`
- `htmlTrim(s text) → text`
- `htmlSplit(s text, delim text) → list text`
- `htmlJoin(parts list text, delim text) → text`
- `htmlReplace(s text, from text, to text) → text`

## std/c/parselog

`import "std/c/parselog"` · `use parselog`

- `logLen(s text) → number`
- `logUpper(s text) → text`
- `logLower(s text) → text`
- `logTrim(s text) → text`
- `logSplit(s text, delim text) → list text`
- `logJoin(parts list text, delim text) → text`
- `logReplace(s text, from text, to text) → text`

## std/c/parseuri

`import "std/c/parseuri"` · `use parseuri`

- `scheme(uri text) → text`
- `host(uri text) → text`
- `path(uri text) → text`
- `query(uri text) → text`
- `fragment(uri text) → text`
- `port(uri text) → number`
- `isValid(uri text) → bool`

## std/c/parsemime

`import "std/c/parsemime"` · `use parsemime`

- `mimeLen(s text) → number`
- `mimeUpper(s text) → text`
- `mimeLower(s text) → text`
- `mimeTrim(s text) → text`
- `mimeSplit(s text, delim text) → list text`
- `mimeJoin(parts list text, delim text) → text`
- `mimeReplace(s text, from text, to text) → text`

## std/c/parsehex

`import "std/c/parsehex"` · `use parsehex`

- `decode(hex text) → list number`
- `encode(bytes list number) → text`
- `nibbleCount(hex text) → number`
- `byteCount(hex text) → number`
- `isHex(s text) → bool`
- `roundTrip(bytes list number) → bool`

## std/c/parsebinary

`import "std/c/parsebinary"` · `use parsebinary`

- `binaLen(s text) → number`
- `binaUpper(s text) → text`
- `binaLower(s text) → text`
- `binaTrim(s text) → text`
- `binaSplit(s text, delim text) → list text`
- `binaJoin(parts list text, delim text) → text`
- `binaReplace(s text, from text, to text) → text`

## std/c/parsetemplate

`import "std/c/parsetemplate"` · `use parsetemplate`

- `tempLen(s text) → number`
- `tempUpper(s text) → text`
- `tempLower(s text) → text`
- `tempTrim(s text) → text`
- `tempSplit(s text, delim text) → list text`
- `tempJoin(parts list text, delim text) → text`
- `tempReplace(s text, from text, to text) → text`

## std/c/parseexpr

`import "std/c/parseexpr"` · `use parseexpr`

- `exprLen(s text) → number`
- `exprUpper(s text) → text`
- `exprLower(s text) → text`
- `exprTrim(s text) → text`
- `exprSplit(s text, delim text) → list text`
- `exprJoin(parts list text, delim text) → text`
- `exprReplace(s text, from text, to text) → text`

## std/c/csvfilter

`import "std/c/csvfilter"` · `use csvfilter`

- `filtSum(v list number) → number`
- `filtMean(v list number) → number`
- `filtMin(v list number) → number`
- `filtMax(v list number) → number`
- `filtVar(v list number) → number`
- `filtStd(v list number) → number`
- `filtNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvgroup

`import "std/c/csvgroup"` · `use csvgroup`

- `groupSum(values list number, keys list number) → list number`
- `groupCount(keys list number) → list number`
- `groupMean(values list number, keys list number) → list number`
- `uniqueKeys(keys list number) → list number`
- `groupMax(values list number, keys list number) → list number`
- `numGroups(keys list number) → number`

## std/c/csvaggregate

`import "std/c/csvaggregate"` · `use csvaggregate`

- `aggrSum(v list number) → number`
- `aggrMean(v list number) → number`
- `aggrMin(v list number) → number`
- `aggrMax(v list number) → number`
- `aggrVar(v list number) → number`
- `aggrStd(v list number) → number`
- `aggrNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvjoin

`import "std/c/csvjoin"` · `use csvjoin`

- `joinSum(v list number) → number`
- `joinMean(v list number) → number`
- `joinMin(v list number) → number`
- `joinMax(v list number) → number`
- `joinVar(v list number) → number`
- `joinStd(v list number) → number`
- `joinNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvpivot

`import "std/c/csvpivot"` · `use csvpivot`

- `pivoSum(v list number) → number`
- `pivoMean(v list number) → number`
- `pivoMin(v list number) → number`
- `pivoMax(v list number) → number`
- `pivoVar(v list number) → number`
- `pivoStd(v list number) → number`
- `pivoNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvsort

`import "std/c/csvsort"` · `use csvsort`

- `sortAsc(col list number) → list number`
- `sortDesc(col list number) → list number`
- `argsort(col list number) → list number`
- `rank(col list number) → list number`
- `topK(col list number, k number) → list number`
- `bottomK(col list number, k number) → list number`

## std/c/csvselect

`import "std/c/csvselect"` · `use csvselect`

- `seleSum(v list number) → number`
- `seleMean(v list number) → number`
- `seleMin(v list number) → number`
- `seleMax(v list number) → number`
- `seleVar(v list number) → number`
- `seleStd(v list number) → number`
- `seleNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvdistinct

`import "std/c/csvdistinct"` · `use csvdistinct`

- `distSum(v list number) → number`
- `distMean(v list number) → number`
- `distMin(v list number) → number`
- `distMax(v list number) → number`
- `distVar(v list number) → number`
- `distStd(v list number) → number`
- `distNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvlimit

`import "std/c/csvlimit"` · `use csvlimit`

- `limiSum(v list number) → number`
- `limiMean(v list number) → number`
- `limiMin(v list number) → number`
- `limiMax(v list number) → number`
- `limiVar(v list number) → number`
- `limiStd(v list number) → number`
- `limiNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvhaving

`import "std/c/csvhaving"` · `use csvhaving`

- `haviSum(v list number) → number`
- `haviMean(v list number) → number`
- `haviMin(v list number) → number`
- `haviMax(v list number) → number`
- `haviVar(v list number) → number`
- `haviStd(v list number) → number`
- `haviNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvunion

`import "std/c/csvunion"` · `use csvunion`

- `unioSum(v list number) → number`
- `unioMean(v list number) → number`
- `unioMin(v list number) → number`
- `unioMax(v list number) → number`
- `unioVar(v list number) → number`
- `unioStd(v list number) → number`
- `unioNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvwindow

`import "std/c/csvwindow"` · `use csvwindow`

- `windSum(v list number) → number`
- `windMean(v list number) → number`
- `windMin(v list number) → number`
- `windMax(v list number) → number`
- `windVar(v list number) → number`
- `windStd(v list number) → number`
- `windNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvnormalize

`import "std/c/csvnormalize"` · `use csvnormalize`

- `normSum(v list number) → number`
- `normMean(v list number) → number`
- `normMin(v list number) → number`
- `normMax(v list number) → number`
- `normVar(v list number) → number`
- `normStd(v list number) → number`
- `normNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvrollup

`import "std/c/csvrollup"` · `use csvrollup`

- `rollSum(v list number) → number`
- `rollMean(v list number) → number`
- `rollMin(v list number) → number`
- `rollMax(v list number) → number`
- `rollVar(v list number) → number`
- `rollStd(v list number) → number`
- `rollNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvsample

`import "std/c/csvsample"` · `use csvsample`

- `sampSum(v list number) → number`
- `sampMean(v list number) → number`
- `sampMin(v list number) → number`
- `sampMax(v list number) → number`
- `sampVar(v list number) → number`
- `sampStd(v list number) → number`
- `sampNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/simmonte

`import "std/c/simmonte"` · `use simmonte`

- `estimatePi(samples number, seed number) → number`
- `integrate(samples number, seed number, a number, b number) → number`
- `randomNormal(n number, seed number) → list number`
- `confidence95(samples list number) → list number`
- `bootstrapMean(data list number, samples number, seed number) → number`
- `varianceReduction(samples number, seed number) → number`

## std/c/simmarkov

`import "std/c/simmarkov"` · `use simmarkov`

- `steadyState(trans list number, states number) → list number`
- `simulate(trans list number, states number, steps number, seed number) → list number`
- `transitionProb(trans list number, states number, from number, to number) → number`
- `expectedSteps(trans list number, states number, target number) → number`
- `isStochastic(trans list number, states number) → bool`
- `mixingTime(trans list number, states number) → number`

## std/c/simrandomwalk

`import "std/c/simrandomwalk"` · `use simrandomwalk`

- `randSum(v list number) → number`
- `randMean(v list number) → number`
- `randMin(v list number) → number`
- `randMax(v list number) → number`
- `randVar(v list number) → number`
- `randStd(v list number) → number`
- `randNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/simbrownian

`import "std/c/simbrownian"` · `use simbrownian`

- `browSum(v list number) → number`
- `browMean(v list number) → number`
- `browMin(v list number) → number`
- `browMax(v list number) → number`
- `browVar(v list number) → number`
- `browStd(v list number) → number`
- `browNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/simpoisson

`import "std/c/simpoisson"` · `use simpoisson`

- `poisSum(v list number) → number`
- `poisMean(v list number) → number`
- `poisMin(v list number) → number`
- `poisMax(v list number) → number`
- `poisVar(v list number) → number`
- `poisStd(v list number) → number`
- `poisNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/simqueue

`import "std/c/simqueue"` · `use simqueue`

- `queuSum(v list number) → number`
- `queuMean(v list number) → number`
- `queuMin(v list number) → number`
- `queuMax(v list number) → number`
- `queuVar(v list number) → number`
- `queuStd(v list number) → number`
- `queuNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/siminventory

`import "std/c/siminventory"` · `use siminventory`

- `inveSum(v list number) → number`
- `inveMean(v list number) → number`
- `inveMin(v list number) → number`
- `inveMax(v list number) → number`
- `inveVar(v list number) → number`
- `inveStd(v list number) → number`
- `inveNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/simdiscrete

`import "std/c/simdiscrete"` · `use simdiscrete`

- `discSum(v list number) → number`
- `discMean(v list number) → number`
- `discMin(v list number) → number`
- `discMax(v list number) → number`
- `discVar(v list number) → number`
- `discStd(v list number) → number`
- `discNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/simlorenz

`import "std/c/simlorenz"` · `use simlorenz`

- `loreSum(v list number) → number`
- `loreMean(v list number) → number`
- `loreMin(v list number) → number`
- `loreMax(v list number) → number`
- `loreVar(v list number) → number`
- `loreStd(v list number) → number`
- `loreNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/simbirth

`import "std/c/simbirth"` · `use simbirth`

- `birtSum(v list number) → number`
- `birtMean(v list number) → number`
- `birtMin(v list number) → number`
- `birtMax(v list number) → number`
- `birtVar(v list number) → number`
- `birtStd(v list number) → number`
- `birtNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/finoption

`import "std/c/finoption"` · `use finoption`

- `blackScholes(spot number, strike number, rate number, vol number, time number) → number`
- `putPrice(spot number, strike number, rate number, vol number, time number) → number`
- `intrinsic(spot number, strike number) → number`
- `timeValue(spot number, strike number, rate number, vol number, time number) → number`
- `delta(spot number, strike number, rate number, vol number, time number) → number`
- `gamma(spot number, strike number, rate number, vol number, time number) → number`
- `vega(spot number, strike number, rate number, vol number, time number) → number`

## std/c/finbond

`import "std/c/finbond"` · `use finbond`

- `pv(face number, rate number, years number, coupon number) → number`
- `ytm(price number, face number, coupon number, years number) → number`
- `duration(face number, rate number, years number, coupon number) → number`
- `convexity(face number, rate number, years number, coupon number) → number`
- `couponYield(coupon number, price number) → number`
- `accruedInterest(coupon number, days number) → number`

## std/c/finportfolio

`import "std/c/finportfolio"` · `use finportfolio`

- `portSum(v list number) → number`
- `portMean(v list number) → number`
- `portMin(v list number) → number`
- `portMax(v list number) → number`
- `portVar(v list number) → number`
- `portStd(v list number) → number`
- `portNorm(v list number) → list number`

## std/c/finblack

`import "std/c/finblack"` · `use finblack`

- `blacSum(v list number) → number`
- `blacMean(v list number) → number`
- `blacMin(v list number) → number`
- `blacMax(v list number) → number`
- `blacVar(v list number) → number`
- `blacStd(v list number) → number`
- `blacNorm(v list number) → list number`

## std/c/fingreeks

`import "std/c/fingreeks"` · `use fingreeks`

- `greeSum(v list number) → number`
- `greeMean(v list number) → number`
- `greeMin(v list number) → number`
- `greeMax(v list number) → number`
- `greeVar(v list number) → number`
- `greeStd(v list number) → number`
- `greeNorm(v list number) → list number`

## std/c/finyield

`import "std/c/finyield"` · `use finyield`

- `yielSum(v list number) → number`
- `yielMean(v list number) → number`
- `yielMin(v list number) → number`
- `yielMax(v list number) → number`
- `yielVar(v list number) → number`
- `yielStd(v list number) → number`
- `yielNorm(v list number) → list number`

## std/c/finsharpe

`import "std/c/finsharpe"` · `use finsharpe`

- `sharpe(returns list number, rf number) → number`
- `sortino(returns list number, rf number) → number`
- `maxDrawdown(prices list number) → number`
- `calmar(returns list number, prices list number) → number`
- `volatility(returns list number) → number`
- `annualizedReturn(returns list number, periods number) → number`

## std/c/finvar

`import "std/c/finvar"` · `use finvar`

- `varSum(v list number) → number`
- `varMean(v list number) → number`
- `varMin(v list number) → number`
- `varMax(v list number) → number`
- `varVar(v list number) → number`
- `varStd(v list number) → number`
- `varNorm(v list number) → list number`

## std/c/finforex

`import "std/c/finforex"` · `use finforex`

- `foreSum(v list number) → number`
- `foreMean(v list number) → number`
- `foreMin(v list number) → number`
- `foreMax(v list number) → number`
- `foreVar(v list number) → number`
- `foreStd(v list number) → number`
- `foreNorm(v list number) → list number`

## std/c/finamort

`import "std/c/finamort"` · `use finamort`

- `amorSum(v list number) → number`
- `amorMean(v list number) → number`
- `amorMin(v list number) → number`
- `amorMax(v list number) → number`
- `amorVar(v list number) → number`
- `amorStd(v list number) → number`
- `amorNorm(v list number) → list number`

## std/c/finfutures

`import "std/c/finfutures"` · `use finfutures`

- `futuSum(v list number) → number`
- `futuMean(v list number) → number`
- `futuMin(v list number) → number`
- `futuMax(v list number) → number`
- `futuVar(v list number) → number`
- `futuStd(v list number) → number`
- `futuNorm(v list number) → list number`

## std/c/finswap

`import "std/c/finswap"` · `use finswap`

- `swapSum(v list number) → number`
- `swapMean(v list number) → number`
- `swapMin(v list number) → number`
- `swapMax(v list number) → number`
- `swapVar(v list number) → number`
- `swapStd(v list number) → number`
- `swapNorm(v list number) → list number`

## std/c/finrisk

`import "std/c/finrisk"` · `use finrisk`

- `riskSum(v list number) → number`
- `riskMean(v list number) → number`
- `riskMin(v list number) → number`
- `riskMax(v list number) → number`
- `riskVar(v list number) → number`
- `riskStd(v list number) → number`
- `riskNorm(v list number) → list number`

## std/c/finhedge

`import "std/c/finhedge"` · `use finhedge`

- `hedgSum(v list number) → number`
- `hedgMean(v list number) → number`
- `hedgMin(v list number) → number`
- `hedgMax(v list number) → number`
- `hedgVar(v list number) → number`
- `hedgStd(v list number) → number`
- `hedgNorm(v list number) → list number`

## std/c/findividend

`import "std/c/findividend"` · `use findividend`

- `diviSum(v list number) → number`
- `diviMean(v list number) → number`
- `diviMin(v list number) → number`
- `diviMax(v list number) → number`
- `diviVar(v list number) → number`
- `diviStd(v list number) → number`
- `diviNorm(v list number) → list number`

## std/c/sigconv

`import "std/c/sigconv"` · `use sigconv`

- `convolve(a list number, b list number) → list number`
- `crossCorr(a list number, b list number) → list number`
- `movingAvg(v list number, win number) → list number`
- `deconvSimple(signal list number, kernel list number) → list number`
- `energy(v list number) → number`
- `normalize(v list number) → list number`

## std/c/sigfft

`import "std/c/sigfft"` · `use sigfft`

- `dft(signal list number) → list number`
- `magnitude(signal list number) → list number`
- `powerSpectrum(signal list number) → list number`
- `dominantFreq(signal list number) → number`
- `inverseDft(spectrum list number, n number) → list number`
- `bandEnergy(signal list number, lo number, hi number) → number`

## std/c/sigpoly

`import "std/c/sigpoly"` · `use sigpoly`

- `polySum(v list number) → number`
- `polyMean(v list number) → number`
- `polyMin(v list number) → number`
- `polyMax(v list number) → number`
- `polyVar(v list number) → number`
- `polyStd(v list number) → number`
- `polyNorm(v list number) → list number`

## std/c/sigeigen

`import "std/c/sigeigen"` · `use sigeigen`

- `eigeSum(v list number) → number`
- `eigeMean(v list number) → number`
- `eigeMin(v list number) → number`
- `eigeMax(v list number) → number`
- `eigeVar(v list number) → number`
- `eigeStd(v list number) → number`
- `eigeNorm(v list number) → list number`

## std/c/sigmatrix

`import "std/c/sigmatrix"` · `use sigmatrix`

- `matrSum(v list number) → number`
- `matrMean(v list number) → number`
- `matrMin(v list number) → number`
- `matrMax(v list number) → number`
- `matrVar(v list number) → number`
- `matrStd(v list number) → number`
- `matrNorm(v list number) → list number`

## std/c/sigintegral

`import "std/c/sigintegral"` · `use sigintegral`

- `inteSum(v list number) → number`
- `inteMean(v list number) → number`
- `inteMin(v list number) → number`
- `inteMax(v list number) → number`
- `inteVar(v list number) → number`
- `inteStd(v list number) → number`
- `inteNorm(v list number) → list number`

## std/c/sigderivative

`import "std/c/sigderivative"` · `use sigderivative`

- `deriSum(v list number) → number`
- `deriMean(v list number) → number`
- `deriMin(v list number) → number`
- `deriMax(v list number) → number`
- `deriVar(v list number) → number`
- `deriStd(v list number) → number`
- `deriNorm(v list number) → list number`

## std/c/sigfilter

`import "std/c/sigfilter"` · `use sigfilter`

- `lowPass(v list number, alpha number) → list number`
- `highPass(v list number, alpha number) → list number`
- `medianFilter(v list number, win number) → list number`
- `savgol(v list number, win number) → list number`
- `bandpass(v list number, lo number, hi number) → list number`
- `snr(signal list number, noise list number) → number`

## std/c/sigwavelet

`import "std/c/sigwavelet"` · `use sigwavelet`

- `waveSum(v list number) → number`
- `waveMean(v list number) → number`
- `waveMin(v list number) → number`
- `waveMax(v list number) → number`
- `waveVar(v list number) → number`
- `waveStd(v list number) → number`
- `waveNorm(v list number) → list number`

## std/c/sigresample

`import "std/c/sigresample"` · `use sigresample`

- `resaSum(v list number) → number`
- `resaMean(v list number) → number`
- `resaMin(v list number) → number`
- `resaMax(v list number) → number`
- `resaVar(v list number) → number`
- `resaStd(v list number) → number`
- `resaNorm(v list number) → list number`

## std/c/siginterpolate

`import "std/c/siginterpolate"` · `use siginterpolate`

- `inteSum(v list number) → number`
- `inteMean(v list number) → number`
- `inteMin(v list number) → number`
- `inteMax(v list number) → number`
- `inteVar(v list number) → number`
- `inteStd(v list number) → number`
- `inteNorm(v list number) → list number`

## std/c/sigspline

`import "std/c/sigspline"` · `use sigspline`

- `spliSum(v list number) → number`
- `spliMean(v list number) → number`
- `spliMin(v list number) → number`
- `spliMax(v list number) → number`
- `spliVar(v list number) → number`
- `spliStd(v list number) → number`
- `spliNorm(v list number) → list number`

## std/c/sigcorrel

`import "std/c/sigcorrel"` · `use sigcorrel`

- `corrSum(v list number) → number`
- `corrMean(v list number) → number`
- `corrMin(v list number) → number`
- `corrMax(v list number) → number`
- `corrVar(v list number) → number`
- `corrStd(v list number) → number`
- `corrNorm(v list number) → list number`

## std/c/sigautocorr

`import "std/c/sigautocorr"` · `use sigautocorr`

- `autoSum(v list number) → number`
- `autoMean(v list number) → number`
- `autoMin(v list number) → number`
- `autoMax(v list number) → number`
- `autoVar(v list number) → number`
- `autoStd(v list number) → number`
- `autoNorm(v list number) → list number`

## std/c/sigpower

`import "std/c/sigpower"` · `use sigpower`

- `poweSum(v list number) → number`
- `poweMean(v list number) → number`
- `poweMin(v list number) → number`
- `poweMax(v list number) → number`
- `poweVar(v list number) → number`
- `poweStd(v list number) → number`
- `poweNorm(v list number) → list number`

## std/c/nlpstem

`import "std/c/nlpstem"` · `use nlpstem`

- `stemLen(s text) → number`
- `stemUpper(s text) → text`
- `stemLower(s text) → text`
- `stemTrim(s text) → text`
- `stemSplit(s text, delim text) → list text`
- `stemJoin(parts list text, delim text) → text`
- `stemReplace(s text, from text, to text) → text`

## std/c/nlplevenshtein

`import "std/c/nlplevenshtein"` · `use nlplevenshtein`

- `distance(a text, b text) → number`
- `similarity(a text, b text) → number`
- `ratio(a text, b text) → number`
- `isClose(a text, b text, maxDist number) → bool`
- `normalizedDist(a text, b text) → number`
- `longestCommon(a text, b text) → number`

## std/c/nlpjaccard

`import "std/c/nlpjaccard"` · `use nlpjaccard`

- `similarity(a text, b text) → number`
- `tokenJaccard(a text, b text) → number`
- `distance(a text, b text) → number`
- `ngramJaccard(a text, b text, n number) → number`
- `overlap(a text, b text) → number`
- `dice(a text, b text) → number`

## std/c/nlpedit

`import "std/c/nlpedit"` · `use nlpedit`

- `editLen(s text) → number`
- `editUpper(s text) → text`
- `editLower(s text) → text`
- `editTrim(s text) → text`
- `editSplit(s text, delim text) → list text`
- `editJoin(parts list text, delim text) → text`
- `editReplace(s text, from text, to text) → text`

## std/c/nlptoken

`import "std/c/nlptoken"` · `use nlptoken`

- `tokeLen(s text) → number`
- `tokeUpper(s text) → text`
- `tokeLower(s text) → text`
- `tokeTrim(s text) → text`
- `tokeSplit(s text, delim text) → list text`
- `tokeJoin(parts list text, delim text) → text`
- `tokeReplace(s text, from text, to text) → text`

## std/c/nlpngram

`import "std/c/nlpngram"` · `use nlpngram`

- `ngraLen(s text) → number`
- `ngraUpper(s text) → text`
- `ngraLower(s text) → text`
- `ngraTrim(s text) → text`
- `ngraSplit(s text, delim text) → list text`
- `ngraJoin(parts list text, delim text) → text`
- `ngraReplace(s text, from text, to text) → text`

## std/c/nlpbow

`import "std/c/nlpbow"` · `use nlpbow`

- `bowLen(s text) → number`
- `bowUpper(s text) → text`
- `bowLower(s text) → text`
- `bowTrim(s text) → text`
- `bowSplit(s text, delim text) → list text`
- `bowJoin(parts list text, delim text) → text`
- `bowReplace(s text, from text, to text) → text`

## std/c/nlpstop

`import "std/c/nlpstop"` · `use nlpstop`

- `stopLen(s text) → number`
- `stopUpper(s text) → text`
- `stopLower(s text) → text`
- `stopTrim(s text) → text`
- `stopSplit(s text, delim text) → list text`
- `stopJoin(parts list text, delim text) → text`
- `stopReplace(s text, from text, to text) → text`

## std/c/nlpphrase

`import "std/c/nlpphrase"` · `use nlpphrase`

- `phraLen(s text) → number`
- `phraUpper(s text) → text`
- `phraLower(s text) → text`
- `phraTrim(s text) → text`
- `phraSplit(s text, delim text) → list text`
- `phraJoin(parts list text, delim text) → text`
- `phraReplace(s text, from text, to text) → text`

## std/c/nlpsentiment

`import "std/c/nlpsentiment"` · `use nlpsentiment`

- `sentLen(s text) → number`
- `sentUpper(s text) → text`
- `sentLower(s text) → text`
- `sentTrim(s text) → text`
- `sentSplit(s text, delim text) → list text`
- `sentJoin(parts list text, delim text) → text`
- `sentReplace(s text, from text, to text) → text`

## std/c/nlpkeyword

`import "std/c/nlpkeyword"` · `use nlpkeyword`

- `keywLen(s text) → number`
- `keywUpper(s text) → text`
- `keywLower(s text) → text`
- `keywTrim(s text) → text`
- `keywSplit(s text, delim text) → list text`
- `keywJoin(parts list text, delim text) → text`
- `keywReplace(s text, from text, to text) → text`

## std/c/nlptfidf

`import "std/c/nlptfidf"` · `use nlptfidf`

- `tf(doc text, term text) → number`
- `idf(term text, corpus list text) → number`
- `tfidf(doc text, term text, corpus list text) → number`
- `docVector(doc text, terms list text, corpus list text) → list number`
- `cosineSim(a list number, b list number) → number`
- `rankTerms(doc text, corpus list text) → list text`

## std/c/nlpoverlap

`import "std/c/nlpoverlap"` · `use nlpoverlap`

- `overLen(s text) → number`
- `overUpper(s text) → text`
- `overLower(s text) → text`
- `overTrim(s text) → text`
- `overSplit(s text, delim text) → list text`
- `overJoin(parts list text, delim text) → text`
- `overReplace(s text, from text, to text) → text`

## std/c/nlpsimhash

`import "std/c/nlpsimhash"` · `use nlpsimhash`

- `simhLen(s text) → number`
- `simhUpper(s text) → text`
- `simhLower(s text) → text`
- `simhTrim(s text) → text`
- `simhSplit(s text, delim text) → list text`
- `simhJoin(parts list text, delim text) → text`
- `simhReplace(s text, from text, to text) → text`

## std/c/nlpcompress

`import "std/c/nlpcompress"` · `use nlpcompress`

- `compLen(s text) → number`
- `compUpper(s text) → text`
- `compLower(s text) → text`
- `compTrim(s text) → text`
- `compSplit(s text, delim text) → list text`
- `compJoin(parts list text, delim text) → text`
- `compReplace(s text, from text, to text) → text`

## std/c/tsma

`import "std/c/tsma"` · `use tsma`

- `sma(v list number, win number) → list number`
- `wma(v list number, win number) → list number`
- `dema(v list number, win number) → list number`
- `crossover(v list number, fast number, slow number) → list number`
- `signal(v list number, fast number, slow number) → number`
- `trend(v list number, win number) → number`

## std/c/tsema

`import "std/c/tsema"` · `use tsema`

- `ema(v list number, alpha number) → list number`
- `emaSpan(v list number, span number) → list number`
- `macd(v list number) → list number`
- `macdSignal(v list number) → list number`
- `histogram(v list number) → list number`
- `lastEma(v list number, alpha number) → number`

## std/c/tsautocorr

`import "std/c/tsautocorr"` · `use tsautocorr`

- `autoSum(v list number) → number`
- `autoMean(v list number) → number`
- `autoMin(v list number) → number`
- `autoMax(v list number) → number`
- `autoVar(v list number) → number`
- `autoStd(v list number) → number`
- `autoNorm(v list number) → list number`

## std/c/tsseason

`import "std/c/tsseason"` · `use tsseason`

- `seasSum(v list number) → number`
- `seasMean(v list number) → number`
- `seasMin(v list number) → number`
- `seasMax(v list number) → number`
- `seasVar(v list number) → number`
- `seasStd(v list number) → number`
- `seasNorm(v list number) → list number`

## std/c/tsdecompose

`import "std/c/tsdecompose"` · `use tsdecompose`

- `decoSum(v list number) → number`
- `decoMean(v list number) → number`
- `decoMin(v list number) → number`
- `decoMax(v list number) → number`
- `decoVar(v list number) → number`
- `decoStd(v list number) → number`
- `decoNorm(v list number) → list number`

## std/c/tsforecast

`import "std/c/tsforecast"` · `use tsforecast`

- `foreSum(v list number) → number`
- `foreMean(v list number) → number`
- `foreMin(v list number) → number`
- `foreMax(v list number) → number`
- `foreVar(v list number) → number`
- `foreStd(v list number) → number`
- `foreNorm(v list number) → list number`

## std/c/tsanomaly

`import "std/c/tsanomaly"` · `use tsanomaly`

- `anomSum(v list number) → number`
- `anomMean(v list number) → number`
- `anomMin(v list number) → number`
- `anomMax(v list number) → number`
- `anomVar(v list number) → number`
- `anomStd(v list number) → number`
- `anomNorm(v list number) → list number`

## std/c/tsrolling

`import "std/c/tsrolling"` · `use tsrolling`

- `rollSum(v list number) → number`
- `rollMean(v list number) → number`
- `rollMin(v list number) → number`
- `rollMax(v list number) → number`
- `rollVar(v list number) → number`
- `rollStd(v list number) → number`
- `rollNorm(v list number) → list number`

## std/c/tscumulative

`import "std/c/tscumulative"` · `use tscumulative`

- `cumuSum(v list number) → number`
- `cumuMean(v list number) → number`
- `cumuMin(v list number) → number`
- `cumuMax(v list number) → number`
- `cumuVar(v list number) → number`
- `cumuStd(v list number) → number`
- `cumuNorm(v list number) → list number`

## std/c/tsdiff

`import "std/c/tsdiff"` · `use tsdiff`

- `diff(v list number, order number) → list number`
- `pctChange(v list number) → list number`
- `logReturn(v list number) → list number`
- `cumReturn(v list number) → list number`
- `seasonalDiff(v list number, period number) → list number`
- `integrate(v list number, start number) → list number`

## std/c/geomhull

`import "std/c/geomhull"` · `use geomhull`

- `hullSum(v list number) → number`
- `hullMean(v list number) → number`
- `hullMin(v list number) → number`
- `hullMax(v list number) → number`
- `hullVar(v list number) → number`
- `hullStd(v list number) → number`
- `hullNorm(v list number) → list number`

## std/c/geompolygon

`import "std/c/geompolygon"` · `use geompolygon`

- `polySum(v list number) → number`
- `polyMean(v list number) → number`
- `polyMin(v list number) → number`
- `polyMax(v list number) → number`
- `polyVar(v list number) → number`
- `polyStd(v list number) → number`
- `polyNorm(v list number) → list number`

## std/c/geomline

`import "std/c/geomline"` · `use geomline`

- `lineSum(v list number) → number`
- `lineMean(v list number) → number`
- `lineMin(v list number) → number`
- `lineMax(v list number) → number`
- `lineVar(v list number) → number`
- `lineStd(v list number) → number`
- `lineNorm(v list number) → list number`

## std/c/geomcircle

`import "std/c/geomcircle"` · `use geomcircle`

- `euclidean2d(x1 number, y1 number, x2 number, y2 number) → number`
- `area(r number) → number`
- `circumference(r number) → number`
- `contains(cx number, cy number, r number, px number, py number) → bool`
- `pointAt(cx number, cy number, r number, angle number) → list number`
- `intersectArea(r1 number, r2 number, d number) → number`

## std/c/geombezier

`import "std/c/geombezier"` · `use geombezier`

- `beziSum(v list number) → number`
- `beziMean(v list number) → number`
- `beziMin(v list number) → number`
- `beziMax(v list number) → number`
- `beziVar(v list number) → number`
- `beziStd(v list number) → number`
- `beziNorm(v list number) → list number`

## std/c/geomclip

`import "std/c/geomclip"` · `use geomclip`

- `clipSum(v list number) → number`
- `clipMean(v list number) → number`
- `clipMin(v list number) → number`
- `clipMax(v list number) → number`
- `clipVar(v list number) → number`
- `clipStd(v list number) → number`
- `clipNorm(v list number) → list number`

## std/c/geomrotate

`import "std/c/geomrotate"` · `use geomrotate`

- `rotaSum(v list number) → number`
- `rotaMean(v list number) → number`
- `rotaMin(v list number) → number`
- `rotaMax(v list number) → number`
- `rotaVar(v list number) → number`
- `rotaStd(v list number) → number`
- `rotaNorm(v list number) → list number`

## std/c/geomscale

`import "std/c/geomscale"` · `use geomscale`

- `scalSum(v list number) → number`
- `scalMean(v list number) → number`
- `scalMin(v list number) → number`
- `scalMax(v list number) → number`
- `scalVar(v list number) → number`
- `scalStd(v list number) → number`
- `scalNorm(v list number) → list number`

## std/c/geomintersect

`import "std/c/geomintersect"` · `use geomintersect`

- `inteSum(v list number) → number`
- `inteMean(v list number) → number`
- `inteMin(v list number) → number`
- `inteMax(v list number) → number`
- `inteVar(v list number) → number`
- `inteStd(v list number) → number`
- `inteNorm(v list number) → list number`

## std/c/geomdistance

`import "std/c/geomdistance"` · `use geomdistance`

- `euclidean2d(x1 number, y1 number, x2 number, y2 number) → number`
- `manhattan2d(x1 number, y1 number, x2 number, y2 number) → number`
- `chebyshev2d(x1 number, y1 number, x2 number, y2 number) → number`
- `pointToLine(px number, py number, x1 number, y1 number, x2 number, y2 number) → number`
- `pairwiseDist(points list number) → list number`
- `centroid2d(points list number) → list number`
- `bbox2d(points list number) → list number`

## std/c/netip

`import "std/c/netip"` · `use netip`

- `parseOctets(ip text) → list number`
- `toInt(ip text) → number`
- `fromInt(n number) → text`
- `isPrivate(ip text) → bool`
- `isValid(ip text) → bool`
- `sameSubnet(a text, b text, mask number) → bool`
- `broadcast(ip text, mask number) → text`

## std/c/netsubnet

`import "std/c/netsubnet"` · `use netsubnet`

- `subnLen(s text) → number`
- `subnUpper(s text) → text`
- `subnLower(s text) → text`
- `subnTrim(s text) → text`
- `subnSplit(s text, delim text) → list text`
- `subnJoin(parts list text, delim text) → text`
- `subnReplace(s text, from text, to text) → text`

## std/c/netcidr

`import "std/c/netcidr"` · `use netcidr`

- `prefixLen(cidr text) → number`
- `hostCount(cidr text) → number`
- `maskFromPrefix(prefix number) → number`
- `ipToInt(ip text) → number`
- `networkInt(cidr text) → number`
- `containsIp(cidr text, ip text) → bool`
- `broadcastInt(cidr text) → number`

## std/c/netpacket

`import "std/c/netpacket"` · `use netpacket`

- `packLen(s text) → number`
- `packUpper(s text) → text`
- `packLower(s text) → text`
- `packTrim(s text) → text`
- `packSplit(s text, delim text) → list text`
- `packJoin(parts list text, delim text) → text`
- `packReplace(s text, from text, to text) → text`

## std/c/netmac

`import "std/c/netmac"` · `use netmac`

- `macLen(s text) → number`
- `macUpper(s text) → text`
- `macLower(s text) → text`
- `macTrim(s text) → text`
- `macSplit(s text, delim text) → list text`
- `macJoin(parts list text, delim text) → text`
- `macReplace(s text, from text, to text) → text`

## std/c/netdns

`import "std/c/netdns"` · `use netdns`

- `dnsLen(s text) → number`
- `dnsUpper(s text) → text`
- `dnsLower(s text) → text`
- `dnsTrim(s text) → text`
- `dnsSplit(s text, delim text) → list text`
- `dnsJoin(parts list text, delim text) → text`
- `dnsReplace(s text, from text, to text) → text`

## std/c/netport

`import "std/c/netport"` · `use netport`

- `portLen(s text) → number`
- `portUpper(s text) → text`
- `portLower(s text) → text`
- `portTrim(s text) → text`
- `portSplit(s text, delim text) → list text`
- `portJoin(parts list text, delim text) → text`
- `portReplace(s text, from text, to text) → text`

## std/c/netroute

`import "std/c/netroute"` · `use netroute`

- `routLen(s text) → number`
- `routUpper(s text) → text`
- `routLower(s text) → text`
- `routTrim(s text) → text`
- `routSplit(s text, delim text) → list text`
- `routJoin(parts list text, delim text) → text`
- `routReplace(s text, from text, to text) → text`

## std/c/netping

`import "std/c/netping"` · `use netping`

- `pingLen(s text) → number`
- `pingUpper(s text) → text`
- `pingLower(s text) → text`
- `pingTrim(s text) → text`
- `pingSplit(s text, delim text) → list text`
- `pingJoin(parts list text, delim text) → text`
- `pingReplace(s text, from text, to text) → text`

## std/c/netchecksum

`import "std/c/netchecksum"` · `use netchecksum`

- `ipChecksum(data list number) → number`
- `onesComplement(n number) → number`
- `fold32(sum number) → number`
- `verify(data list number, expected number) → bool`
- `pseudoHeader(src list number, dst list number, proto number, len number) → list number`
- `tcpChecksum(header list number, payload list number) → number`

## std/c/gameminimax

`import "std/c/gameminimax"` · `use gameminimax`

- `minimax(board list number, depth number, maximizing bool) → number`
- `bestMove(board list number, depth number) → number`
- `evaluate(board list number) → number`
- `isTerminal(board list number) → bool`
- `negamax(board list number, depth number, color number) → number`
- `depthReached(depth number) → number`
- `scoreDiff(board list number) → number`

## std/c/gamealphabeta

`import "std/c/gamealphabeta"` · `use gamealphabeta`

- `alphabeta(board list number, depth number, alpha number, beta number, maximizing bool) → number`
- `bestMove(board list number, depth number) → number`
- `pruneCount(board list number, depth number) → number`
- `evaluate(board list number) → number`
- `search(board list number, depth number) → number`
- `isWinning(board list number) → bool`
- `windowSearch(board list number, depth number, window number) → number`

## std/c/gameastar

`import "std/c/gameastar"` · `use gameastar`

- `heuristic(ax number, ay number, bx number, by number) → number`
- `astar(grid list number, width number, start number, goal number) → list number`
- `pathCost(grid list number, width number, start number, goal number) → number`
- `reconstruct(cameFrom list number, current number) → list number`
- `manhattan(ax number, ay number, bx number, by number) → number`
- `octile(ax number, ay number, bx number, by number) → number`
- `openSetSize(grid list number) → number`

## std/c/gamedijkstra

`import "std/c/gamedijkstra"` · `use gamedijkstra`

- `gridDijkstra(grid list number, width number, start number) → list number`
- `shortestCost(grid list number, width number, start number, goal number) → number`
- `reachableCells(grid list number, width number, start number) → number`
- `multiGoal(grid list number, width number, start number, goals list number) → list number`
- `relaxStep(dist list number, grid list number, width number, u number) → list number`
- `maxDist(grid list number, width number, start number) → number`

## std/c/gamemcts

`import "std/c/gamemcts"` · `use gamemcts`

- `uctSelect(wins list number, visits list number, totalVisits number, explore number) → number`
- `rollout(state list number, depth number) → number`
- `simulate(state list number, sims number) → number`
- `bestAction(wins list number, visits list number) → number`
- `updateStats(wins list number, visits list number, action number, reward number) → list number`
- `treePolicy(state list number, actions list number) → number`
- `mctsValue(wins list number, visits list number) → number`

## std/c/gamepathfind

`import "std/c/gamepathfind"` · `use gamepathfind`

- `bfsPath(grid list number, width number, start number, goal number) → list number`
- `pathLen(grid list number, width number, start number, goal number) → number`
- `lineOfSight(grid list number, width number, x0 number, y0 number, x1 number, y1 number) → bool`
- `smoothPath(path list number, grid list number, width number) → list number`
- `waypoints(path list number, step number) → list number`
- `navCost(grid list number, width number, start number, goal number) → number`

## std/c/gamenavmesh

`import "std/c/gamenavmesh"` · `use gamenavmesh`

- `pointInTri(px number, py number, ax number, ay number, bx number, by number, cx number, cy number) → bool`
- `triArea(ax number, ay number, bx number, by number, cx number, cy number) → number`
- `portalMid(a list number, b list number) → list number`
- `navDistance(a list number, b list number) → number`
- `funnelCost(path list number) → number`
- `centroid(ax number, ay number, bx number, by number, cx number, cy number) → list number`
- `meshQuality(ax number, ay number, bx number, by number, cx number, cy number) → number`

## std/c/gamebehavior

`import "std/c/gamebehavior"` · `use gamebehavior`

- `evalSelector(scores list number) → number`
- `evalSequence(scores list number) → number`
- `evalParallel(scores list number) → number`
- `blackboardGet(keys list text, values list number, key text) → number`
- `blackboardSet(keys list text, values list number, key text, val number) → list number`
- `cooldownReady(last number, now number, cd number) → bool`
- `weightedPick(weights list number) → number`

## std/c/gameflood

`import "std/c/gameflood"` · `use gameflood`

- `floodFill(grid list number, width number, start number, newVal number) → list number`
- `connectedRegion(grid list number, width number, start number) → number`
- `countRegions(grid list number, width number) → number`
- `fillDist(grid list number, width number, start number) → list number`
- `reachable(grid list number, width number, start number) → number`
- `boundary(grid list number, width number, start number) → list number`

## std/c/gametree

`import "std/c/gametree"` · `use gametree`

- `branchingFactor(children list number) → number`
- `treeDepth(depths list number) → number`
- `minimaxLeaf(values list number, maxNode bool) → number`
- `expectimax(values list number, probs list number) → number`
- `alphaBetaWindow(alpha number, beta number) → list number`
- `gameTreeSize(branching number, depth number) → number`
- `plyCount(moves list number) → number`
- `bestChild(scores list number) → number`

## std/c/gameultra001

`import "std/c/gameultra001"` · `use gameultra001`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra002

`import "std/c/gameultra002"` · `use gameultra002`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra003

`import "std/c/gameultra003"` · `use gameultra003`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra004

`import "std/c/gameultra004"` · `use gameultra004`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra005

`import "std/c/gameultra005"` · `use gameultra005`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra006

`import "std/c/gameultra006"` · `use gameultra006`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra007

`import "std/c/gameultra007"` · `use gameultra007`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra008

`import "std/c/gameultra008"` · `use gameultra008`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra009

`import "std/c/gameultra009"` · `use gameultra009`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra010

`import "std/c/gameultra010"` · `use gameultra010`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra011

`import "std/c/gameultra011"` · `use gameultra011`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra012

`import "std/c/gameultra012"` · `use gameultra012`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra013

`import "std/c/gameultra013"` · `use gameultra013`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra014

`import "std/c/gameultra014"` · `use gameultra014`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra015

`import "std/c/gameultra015"` · `use gameultra015`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra016

`import "std/c/gameultra016"` · `use gameultra016`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra017

`import "std/c/gameultra017"` · `use gameultra017`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra018

`import "std/c/gameultra018"` · `use gameultra018`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra019

`import "std/c/gameultra019"` · `use gameultra019`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra020

`import "std/c/gameultra020"` · `use gameultra020`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra021

`import "std/c/gameultra021"` · `use gameultra021`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra022

`import "std/c/gameultra022"` · `use gameultra022`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra023

`import "std/c/gameultra023"` · `use gameultra023`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra024

`import "std/c/gameultra024"` · `use gameultra024`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra025

`import "std/c/gameultra025"` · `use gameultra025`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra026

`import "std/c/gameultra026"` · `use gameultra026`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra027

`import "std/c/gameultra027"` · `use gameultra027`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra028

`import "std/c/gameultra028"` · `use gameultra028`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra029

`import "std/c/gameultra029"` · `use gameultra029`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra030

`import "std/c/gameultra030"` · `use gameultra030`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra031

`import "std/c/gameultra031"` · `use gameultra031`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra032

`import "std/c/gameultra032"` · `use gameultra032`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra033

`import "std/c/gameultra033"` · `use gameultra033`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra034

`import "std/c/gameultra034"` · `use gameultra034`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra035

`import "std/c/gameultra035"` · `use gameultra035`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra036

`import "std/c/gameultra036"` · `use gameultra036`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra037

`import "std/c/gameultra037"` · `use gameultra037`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra038

`import "std/c/gameultra038"` · `use gameultra038`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra039

`import "std/c/gameultra039"` · `use gameultra039`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra040

`import "std/c/gameultra040"` · `use gameultra040`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra041

`import "std/c/gameultra041"` · `use gameultra041`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra042

`import "std/c/gameultra042"` · `use gameultra042`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra043

`import "std/c/gameultra043"` · `use gameultra043`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra044

`import "std/c/gameultra044"` · `use gameultra044`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra045

`import "std/c/gameultra045"` · `use gameultra045`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra046

`import "std/c/gameultra046"` · `use gameultra046`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra047

`import "std/c/gameultra047"` · `use gameultra047`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra048

`import "std/c/gameultra048"` · `use gameultra048`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra049

`import "std/c/gameultra049"` · `use gameultra049`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra050

`import "std/c/gameultra050"` · `use gameultra050`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra051

`import "std/c/gameultra051"` · `use gameultra051`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra052

`import "std/c/gameultra052"` · `use gameultra052`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra053

`import "std/c/gameultra053"` · `use gameultra053`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra054

`import "std/c/gameultra054"` · `use gameultra054`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra055

`import "std/c/gameultra055"` · `use gameultra055`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra056

`import "std/c/gameultra056"` · `use gameultra056`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra057

`import "std/c/gameultra057"` · `use gameultra057`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra058

`import "std/c/gameultra058"` · `use gameultra058`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra059

`import "std/c/gameultra059"` · `use gameultra059`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra060

`import "std/c/gameultra060"` · `use gameultra060`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra061

`import "std/c/gameultra061"` · `use gameultra061`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra062

`import "std/c/gameultra062"` · `use gameultra062`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra063

`import "std/c/gameultra063"` · `use gameultra063`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra064

`import "std/c/gameultra064"` · `use gameultra064`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra065

`import "std/c/gameultra065"` · `use gameultra065`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra066

`import "std/c/gameultra066"` · `use gameultra066`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra067

`import "std/c/gameultra067"` · `use gameultra067`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra068

`import "std/c/gameultra068"` · `use gameultra068`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra069

`import "std/c/gameultra069"` · `use gameultra069`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra070

`import "std/c/gameultra070"` · `use gameultra070`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra071

`import "std/c/gameultra071"` · `use gameultra071`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra072

`import "std/c/gameultra072"` · `use gameultra072`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra073

`import "std/c/gameultra073"` · `use gameultra073`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra074

`import "std/c/gameultra074"` · `use gameultra074`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra075

`import "std/c/gameultra075"` · `use gameultra075`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra076

`import "std/c/gameultra076"` · `use gameultra076`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra077

`import "std/c/gameultra077"` · `use gameultra077`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra078

`import "std/c/gameultra078"` · `use gameultra078`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra079

`import "std/c/gameultra079"` · `use gameultra079`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra080

`import "std/c/gameultra080"` · `use gameultra080`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra081

`import "std/c/gameultra081"` · `use gameultra081`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra082

`import "std/c/gameultra082"` · `use gameultra082`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra083

`import "std/c/gameultra083"` · `use gameultra083`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra084

`import "std/c/gameultra084"` · `use gameultra084`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra085

`import "std/c/gameultra085"` · `use gameultra085`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra086

`import "std/c/gameultra086"` · `use gameultra086`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra087

`import "std/c/gameultra087"` · `use gameultra087`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra088

`import "std/c/gameultra088"` · `use gameultra088`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra089

`import "std/c/gameultra089"` · `use gameultra089`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra090

`import "std/c/gameultra090"` · `use gameultra090`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra091

`import "std/c/gameultra091"` · `use gameultra091`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra092

`import "std/c/gameultra092"` · `use gameultra092`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra093

`import "std/c/gameultra093"` · `use gameultra093`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra094

`import "std/c/gameultra094"` · `use gameultra094`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra095

`import "std/c/gameultra095"` · `use gameultra095`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra096

`import "std/c/gameultra096"` · `use gameultra096`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra097

`import "std/c/gameultra097"` · `use gameultra097`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra098

`import "std/c/gameultra098"` · `use gameultra098`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra099

`import "std/c/gameultra099"` · `use gameultra099`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra100

`import "std/c/gameultra100"` · `use gameultra100`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra101

`import "std/c/gameultra101"` · `use gameultra101`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra102

`import "std/c/gameultra102"` · `use gameultra102`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra103

`import "std/c/gameultra103"` · `use gameultra103`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra104

`import "std/c/gameultra104"` · `use gameultra104`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra105

`import "std/c/gameultra105"` · `use gameultra105`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra106

`import "std/c/gameultra106"` · `use gameultra106`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra107

`import "std/c/gameultra107"` · `use gameultra107`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra108

`import "std/c/gameultra108"` · `use gameultra108`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra109

`import "std/c/gameultra109"` · `use gameultra109`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra110

`import "std/c/gameultra110"` · `use gameultra110`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra111

`import "std/c/gameultra111"` · `use gameultra111`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra112

`import "std/c/gameultra112"` · `use gameultra112`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra113

`import "std/c/gameultra113"` · `use gameultra113`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra114

`import "std/c/gameultra114"` · `use gameultra114`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra115

`import "std/c/gameultra115"` · `use gameultra115`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra116

`import "std/c/gameultra116"` · `use gameultra116`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra117

`import "std/c/gameultra117"` · `use gameultra117`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra118

`import "std/c/gameultra118"` · `use gameultra118`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra119

`import "std/c/gameultra119"` · `use gameultra119`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra120

`import "std/c/gameultra120"` · `use gameultra120`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra121

`import "std/c/gameultra121"` · `use gameultra121`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra122

`import "std/c/gameultra122"` · `use gameultra122`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra123

`import "std/c/gameultra123"` · `use gameultra123`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra124

`import "std/c/gameultra124"` · `use gameultra124`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra125

`import "std/c/gameultra125"` · `use gameultra125`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra126

`import "std/c/gameultra126"` · `use gameultra126`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra127

`import "std/c/gameultra127"` · `use gameultra127`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra128

`import "std/c/gameultra128"` · `use gameultra128`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra129

`import "std/c/gameultra129"` · `use gameultra129`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra130

`import "std/c/gameultra130"` · `use gameultra130`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra131

`import "std/c/gameultra131"` · `use gameultra131`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra132

`import "std/c/gameultra132"` · `use gameultra132`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra133

`import "std/c/gameultra133"` · `use gameultra133`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra134

`import "std/c/gameultra134"` · `use gameultra134`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra135

`import "std/c/gameultra135"` · `use gameultra135`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra136

`import "std/c/gameultra136"` · `use gameultra136`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra137

`import "std/c/gameultra137"` · `use gameultra137`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra138

`import "std/c/gameultra138"` · `use gameultra138`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra139

`import "std/c/gameultra139"` · `use gameultra139`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra140

`import "std/c/gameultra140"` · `use gameultra140`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra141

`import "std/c/gameultra141"` · `use gameultra141`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra142

`import "std/c/gameultra142"` · `use gameultra142`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra143

`import "std/c/gameultra143"` · `use gameultra143`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra144

`import "std/c/gameultra144"` · `use gameultra144`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra145

`import "std/c/gameultra145"` · `use gameultra145`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra146

`import "std/c/gameultra146"` · `use gameultra146`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra147

`import "std/c/gameultra147"` · `use gameultra147`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra148

`import "std/c/gameultra148"` · `use gameultra148`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra149

`import "std/c/gameultra149"` · `use gameultra149`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra150

`import "std/c/gameultra150"` · `use gameultra150`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra151

`import "std/c/gameultra151"` · `use gameultra151`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra152

`import "std/c/gameultra152"` · `use gameultra152`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra153

`import "std/c/gameultra153"` · `use gameultra153`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra154

`import "std/c/gameultra154"` · `use gameultra154`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra155

`import "std/c/gameultra155"` · `use gameultra155`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra156

`import "std/c/gameultra156"` · `use gameultra156`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra157

`import "std/c/gameultra157"` · `use gameultra157`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra158

`import "std/c/gameultra158"` · `use gameultra158`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra159

`import "std/c/gameultra159"` · `use gameultra159`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra160

`import "std/c/gameultra160"` · `use gameultra160`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra161

`import "std/c/gameultra161"` · `use gameultra161`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra162

`import "std/c/gameultra162"` · `use gameultra162`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra163

`import "std/c/gameultra163"` · `use gameultra163`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra164

`import "std/c/gameultra164"` · `use gameultra164`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra165

`import "std/c/gameultra165"` · `use gameultra165`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra166

`import "std/c/gameultra166"` · `use gameultra166`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra167

`import "std/c/gameultra167"` · `use gameultra167`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra168

`import "std/c/gameultra168"` · `use gameultra168`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra169

`import "std/c/gameultra169"` · `use gameultra169`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra170

`import "std/c/gameultra170"` · `use gameultra170`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra171

`import "std/c/gameultra171"` · `use gameultra171`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra172

`import "std/c/gameultra172"` · `use gameultra172`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra173

`import "std/c/gameultra173"` · `use gameultra173`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra174

`import "std/c/gameultra174"` · `use gameultra174`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra175

`import "std/c/gameultra175"` · `use gameultra175`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra176

`import "std/c/gameultra176"` · `use gameultra176`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra177

`import "std/c/gameultra177"` · `use gameultra177`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra178

`import "std/c/gameultra178"` · `use gameultra178`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra179

`import "std/c/gameultra179"` · `use gameultra179`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra180

`import "std/c/gameultra180"` · `use gameultra180`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra181

`import "std/c/gameultra181"` · `use gameultra181`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra182

`import "std/c/gameultra182"` · `use gameultra182`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra183

`import "std/c/gameultra183"` · `use gameultra183`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra184

`import "std/c/gameultra184"` · `use gameultra184`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra185

`import "std/c/gameultra185"` · `use gameultra185`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra186

`import "std/c/gameultra186"` · `use gameultra186`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra187

`import "std/c/gameultra187"` · `use gameultra187`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra188

`import "std/c/gameultra188"` · `use gameultra188`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra189

`import "std/c/gameultra189"` · `use gameultra189`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra190

`import "std/c/gameultra190"` · `use gameultra190`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra191

`import "std/c/gameultra191"` · `use gameultra191`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra192

`import "std/c/gameultra192"` · `use gameultra192`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra193

`import "std/c/gameultra193"` · `use gameultra193`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra194

`import "std/c/gameultra194"` · `use gameultra194`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra195

`import "std/c/gameultra195"` · `use gameultra195`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra196

`import "std/c/gameultra196"` · `use gameultra196`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra197

`import "std/c/gameultra197"` · `use gameultra197`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra198

`import "std/c/gameultra198"` · `use gameultra198`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra199

`import "std/c/gameultra199"` · `use gameultra199`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra200

`import "std/c/gameultra200"` · `use gameultra200`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra201

`import "std/c/gameultra201"` · `use gameultra201`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra202

`import "std/c/gameultra202"` · `use gameultra202`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra203

`import "std/c/gameultra203"` · `use gameultra203`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra204

`import "std/c/gameultra204"` · `use gameultra204`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra205

`import "std/c/gameultra205"` · `use gameultra205`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra206

`import "std/c/gameultra206"` · `use gameultra206`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra207

`import "std/c/gameultra207"` · `use gameultra207`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra208

`import "std/c/gameultra208"` · `use gameultra208`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra209

`import "std/c/gameultra209"` · `use gameultra209`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra210

`import "std/c/gameultra210"` · `use gameultra210`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra211

`import "std/c/gameultra211"` · `use gameultra211`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra212

`import "std/c/gameultra212"` · `use gameultra212`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra213

`import "std/c/gameultra213"` · `use gameultra213`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra214

`import "std/c/gameultra214"` · `use gameultra214`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra215

`import "std/c/gameultra215"` · `use gameultra215`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra216

`import "std/c/gameultra216"` · `use gameultra216`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra217

`import "std/c/gameultra217"` · `use gameultra217`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra218

`import "std/c/gameultra218"` · `use gameultra218`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra219

`import "std/c/gameultra219"` · `use gameultra219`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra220

`import "std/c/gameultra220"` · `use gameultra220`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra221

`import "std/c/gameultra221"` · `use gameultra221`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra222

`import "std/c/gameultra222"` · `use gameultra222`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra223

`import "std/c/gameultra223"` · `use gameultra223`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra224

`import "std/c/gameultra224"` · `use gameultra224`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra225

`import "std/c/gameultra225"` · `use gameultra225`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra226

`import "std/c/gameultra226"` · `use gameultra226`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra227

`import "std/c/gameultra227"` · `use gameultra227`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra228

`import "std/c/gameultra228"` · `use gameultra228`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra229

`import "std/c/gameultra229"` · `use gameultra229`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra230

`import "std/c/gameultra230"` · `use gameultra230`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra231

`import "std/c/gameultra231"` · `use gameultra231`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra232

`import "std/c/gameultra232"` · `use gameultra232`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra233

`import "std/c/gameultra233"` · `use gameultra233`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra234

`import "std/c/gameultra234"` · `use gameultra234`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra235

`import "std/c/gameultra235"` · `use gameultra235`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra236

`import "std/c/gameultra236"` · `use gameultra236`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra237

`import "std/c/gameultra237"` · `use gameultra237`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra238

`import "std/c/gameultra238"` · `use gameultra238`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra239

`import "std/c/gameultra239"` · `use gameultra239`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra240

`import "std/c/gameultra240"` · `use gameultra240`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra241

`import "std/c/gameultra241"` · `use gameultra241`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra242

`import "std/c/gameultra242"` · `use gameultra242`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra243

`import "std/c/gameultra243"` · `use gameultra243`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra244

`import "std/c/gameultra244"` · `use gameultra244`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra245

`import "std/c/gameultra245"` · `use gameultra245`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra246

`import "std/c/gameultra246"` · `use gameultra246`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra247

`import "std/c/gameultra247"` · `use gameultra247`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra248

`import "std/c/gameultra248"` · `use gameultra248`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra249

`import "std/c/gameultra249"` · `use gameultra249`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra250

`import "std/c/gameultra250"` · `use gameultra250`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra251

`import "std/c/gameultra251"` · `use gameultra251`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra252

`import "std/c/gameultra252"` · `use gameultra252`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra253

`import "std/c/gameultra253"` · `use gameultra253`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra254

`import "std/c/gameultra254"` · `use gameultra254`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra255

`import "std/c/gameultra255"` · `use gameultra255`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra256

`import "std/c/gameultra256"` · `use gameultra256`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra257

`import "std/c/gameultra257"` · `use gameultra257`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra258

`import "std/c/gameultra258"` · `use gameultra258`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra259

`import "std/c/gameultra259"` · `use gameultra259`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra260

`import "std/c/gameultra260"` · `use gameultra260`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra261

`import "std/c/gameultra261"` · `use gameultra261`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra262

`import "std/c/gameultra262"` · `use gameultra262`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra263

`import "std/c/gameultra263"` · `use gameultra263`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra264

`import "std/c/gameultra264"` · `use gameultra264`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra265

`import "std/c/gameultra265"` · `use gameultra265`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra266

`import "std/c/gameultra266"` · `use gameultra266`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra267

`import "std/c/gameultra267"` · `use gameultra267`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra268

`import "std/c/gameultra268"` · `use gameultra268`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra269

`import "std/c/gameultra269"` · `use gameultra269`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra270

`import "std/c/gameultra270"` · `use gameultra270`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra271

`import "std/c/gameultra271"` · `use gameultra271`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra272

`import "std/c/gameultra272"` · `use gameultra272`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra273

`import "std/c/gameultra273"` · `use gameultra273`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra274

`import "std/c/gameultra274"` · `use gameultra274`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra275

`import "std/c/gameultra275"` · `use gameultra275`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra276

`import "std/c/gameultra276"` · `use gameultra276`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra277

`import "std/c/gameultra277"` · `use gameultra277`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra278

`import "std/c/gameultra278"` · `use gameultra278`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra279

`import "std/c/gameultra279"` · `use gameultra279`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra280

`import "std/c/gameultra280"` · `use gameultra280`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra281

`import "std/c/gameultra281"` · `use gameultra281`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra282

`import "std/c/gameultra282"` · `use gameultra282`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra283

`import "std/c/gameultra283"` · `use gameultra283`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra284

`import "std/c/gameultra284"` · `use gameultra284`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra285

`import "std/c/gameultra285"` · `use gameultra285`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra286

`import "std/c/gameultra286"` · `use gameultra286`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra287

`import "std/c/gameultra287"` · `use gameultra287`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra288

`import "std/c/gameultra288"` · `use gameultra288`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra289

`import "std/c/gameultra289"` · `use gameultra289`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra290

`import "std/c/gameultra290"` · `use gameultra290`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra291

`import "std/c/gameultra291"` · `use gameultra291`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra292

`import "std/c/gameultra292"` · `use gameultra292`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra293

`import "std/c/gameultra293"` · `use gameultra293`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra294

`import "std/c/gameultra294"` · `use gameultra294`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra295

`import "std/c/gameultra295"` · `use gameultra295`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra296

`import "std/c/gameultra296"` · `use gameultra296`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra297

`import "std/c/gameultra297"` · `use gameultra297`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra298

`import "std/c/gameultra298"` · `use gameultra298`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra299

`import "std/c/gameultra299"` · `use gameultra299`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra300

`import "std/c/gameultra300"` · `use gameultra300`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra301

`import "std/c/gameultra301"` · `use gameultra301`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra302

`import "std/c/gameultra302"` · `use gameultra302`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra303

`import "std/c/gameultra303"` · `use gameultra303`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra304

`import "std/c/gameultra304"` · `use gameultra304`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra305

`import "std/c/gameultra305"` · `use gameultra305`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra306

`import "std/c/gameultra306"` · `use gameultra306`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra307

`import "std/c/gameultra307"` · `use gameultra307`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra308

`import "std/c/gameultra308"` · `use gameultra308`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra309

`import "std/c/gameultra309"` · `use gameultra309`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra310

`import "std/c/gameultra310"` · `use gameultra310`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra311

`import "std/c/gameultra311"` · `use gameultra311`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra312

`import "std/c/gameultra312"` · `use gameultra312`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra313

`import "std/c/gameultra313"` · `use gameultra313`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra314

`import "std/c/gameultra314"` · `use gameultra314`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra315

`import "std/c/gameultra315"` · `use gameultra315`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra316

`import "std/c/gameultra316"` · `use gameultra316`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra317

`import "std/c/gameultra317"` · `use gameultra317`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra318

`import "std/c/gameultra318"` · `use gameultra318`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra319

`import "std/c/gameultra319"` · `use gameultra319`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra320

`import "std/c/gameultra320"` · `use gameultra320`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra321

`import "std/c/gameultra321"` · `use gameultra321`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra322

`import "std/c/gameultra322"` · `use gameultra322`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra323

`import "std/c/gameultra323"` · `use gameultra323`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra324

`import "std/c/gameultra324"` · `use gameultra324`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra325

`import "std/c/gameultra325"` · `use gameultra325`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra326

`import "std/c/gameultra326"` · `use gameultra326`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra327

`import "std/c/gameultra327"` · `use gameultra327`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra328

`import "std/c/gameultra328"` · `use gameultra328`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra329

`import "std/c/gameultra329"` · `use gameultra329`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra330

`import "std/c/gameultra330"` · `use gameultra330`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra331

`import "std/c/gameultra331"` · `use gameultra331`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra332

`import "std/c/gameultra332"` · `use gameultra332`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra333

`import "std/c/gameultra333"` · `use gameultra333`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra334

`import "std/c/gameultra334"` · `use gameultra334`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra335

`import "std/c/gameultra335"` · `use gameultra335`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra336

`import "std/c/gameultra336"` · `use gameultra336`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra337

`import "std/c/gameultra337"` · `use gameultra337`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra338

`import "std/c/gameultra338"` · `use gameultra338`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra339

`import "std/c/gameultra339"` · `use gameultra339`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra340

`import "std/c/gameultra340"` · `use gameultra340`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra341

`import "std/c/gameultra341"` · `use gameultra341`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra342

`import "std/c/gameultra342"` · `use gameultra342`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra343

`import "std/c/gameultra343"` · `use gameultra343`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra344

`import "std/c/gameultra344"` · `use gameultra344`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra345

`import "std/c/gameultra345"` · `use gameultra345`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra346

`import "std/c/gameultra346"` · `use gameultra346`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra347

`import "std/c/gameultra347"` · `use gameultra347`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra348

`import "std/c/gameultra348"` · `use gameultra348`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra349

`import "std/c/gameultra349"` · `use gameultra349`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra350

`import "std/c/gameultra350"` · `use gameultra350`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra351

`import "std/c/gameultra351"` · `use gameultra351`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra352

`import "std/c/gameultra352"` · `use gameultra352`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra353

`import "std/c/gameultra353"` · `use gameultra353`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra354

`import "std/c/gameultra354"` · `use gameultra354`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra355

`import "std/c/gameultra355"` · `use gameultra355`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra356

`import "std/c/gameultra356"` · `use gameultra356`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra357

`import "std/c/gameultra357"` · `use gameultra357`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra358

`import "std/c/gameultra358"` · `use gameultra358`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra359

`import "std/c/gameultra359"` · `use gameultra359`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra360

`import "std/c/gameultra360"` · `use gameultra360`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra361

`import "std/c/gameultra361"` · `use gameultra361`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra362

`import "std/c/gameultra362"` · `use gameultra362`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra363

`import "std/c/gameultra363"` · `use gameultra363`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra364

`import "std/c/gameultra364"` · `use gameultra364`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra365

`import "std/c/gameultra365"` · `use gameultra365`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra366

`import "std/c/gameultra366"` · `use gameultra366`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra367

`import "std/c/gameultra367"` · `use gameultra367`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra368

`import "std/c/gameultra368"` · `use gameultra368`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra369

`import "std/c/gameultra369"` · `use gameultra369`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra370

`import "std/c/gameultra370"` · `use gameultra370`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra371

`import "std/c/gameultra371"` · `use gameultra371`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra372

`import "std/c/gameultra372"` · `use gameultra372`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra373

`import "std/c/gameultra373"` · `use gameultra373`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra374

`import "std/c/gameultra374"` · `use gameultra374`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra375

`import "std/c/gameultra375"` · `use gameultra375`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra376

`import "std/c/gameultra376"` · `use gameultra376`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra377

`import "std/c/gameultra377"` · `use gameultra377`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra378

`import "std/c/gameultra378"` · `use gameultra378`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra379

`import "std/c/gameultra379"` · `use gameultra379`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra380

`import "std/c/gameultra380"` · `use gameultra380`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra381

`import "std/c/gameultra381"` · `use gameultra381`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra382

`import "std/c/gameultra382"` · `use gameultra382`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra383

`import "std/c/gameultra383"` · `use gameultra383`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra384

`import "std/c/gameultra384"` · `use gameultra384`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra385

`import "std/c/gameultra385"` · `use gameultra385`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra386

`import "std/c/gameultra386"` · `use gameultra386`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra387

`import "std/c/gameultra387"` · `use gameultra387`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra388

`import "std/c/gameultra388"` · `use gameultra388`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra389

`import "std/c/gameultra389"` · `use gameultra389`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra390

`import "std/c/gameultra390"` · `use gameultra390`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra391

`import "std/c/gameultra391"` · `use gameultra391`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra392

`import "std/c/gameultra392"` · `use gameultra392`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra393

`import "std/c/gameultra393"` · `use gameultra393`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra394

`import "std/c/gameultra394"` · `use gameultra394`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra395

`import "std/c/gameultra395"` · `use gameultra395`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra396

`import "std/c/gameultra396"` · `use gameultra396`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra397

`import "std/c/gameultra397"` · `use gameultra397`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra398

`import "std/c/gameultra398"` · `use gameultra398`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra399

`import "std/c/gameultra399"` · `use gameultra399`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra400

`import "std/c/gameultra400"` · `use gameultra400`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra401

`import "std/c/gameultra401"` · `use gameultra401`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra402

`import "std/c/gameultra402"` · `use gameultra402`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra403

`import "std/c/gameultra403"` · `use gameultra403`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra404

`import "std/c/gameultra404"` · `use gameultra404`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra405

`import "std/c/gameultra405"` · `use gameultra405`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra406

`import "std/c/gameultra406"` · `use gameultra406`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra407

`import "std/c/gameultra407"` · `use gameultra407`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra408

`import "std/c/gameultra408"` · `use gameultra408`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra409

`import "std/c/gameultra409"` · `use gameultra409`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra410

`import "std/c/gameultra410"` · `use gameultra410`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra411

`import "std/c/gameultra411"` · `use gameultra411`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra412

`import "std/c/gameultra412"` · `use gameultra412`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra413

`import "std/c/gameultra413"` · `use gameultra413`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra414

`import "std/c/gameultra414"` · `use gameultra414`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra415

`import "std/c/gameultra415"` · `use gameultra415`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra416

`import "std/c/gameultra416"` · `use gameultra416`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra417

`import "std/c/gameultra417"` · `use gameultra417`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra418

`import "std/c/gameultra418"` · `use gameultra418`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra419

`import "std/c/gameultra419"` · `use gameultra419`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra420

`import "std/c/gameultra420"` · `use gameultra420`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra421

`import "std/c/gameultra421"` · `use gameultra421`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra422

`import "std/c/gameultra422"` · `use gameultra422`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra423

`import "std/c/gameultra423"` · `use gameultra423`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra424

`import "std/c/gameultra424"` · `use gameultra424`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra425

`import "std/c/gameultra425"` · `use gameultra425`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra426

`import "std/c/gameultra426"` · `use gameultra426`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra427

`import "std/c/gameultra427"` · `use gameultra427`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra428

`import "std/c/gameultra428"` · `use gameultra428`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra429

`import "std/c/gameultra429"` · `use gameultra429`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra430

`import "std/c/gameultra430"` · `use gameultra430`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra431

`import "std/c/gameultra431"` · `use gameultra431`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra432

`import "std/c/gameultra432"` · `use gameultra432`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra433

`import "std/c/gameultra433"` · `use gameultra433`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra434

`import "std/c/gameultra434"` · `use gameultra434`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra435

`import "std/c/gameultra435"` · `use gameultra435`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra436

`import "std/c/gameultra436"` · `use gameultra436`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra437

`import "std/c/gameultra437"` · `use gameultra437`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra438

`import "std/c/gameultra438"` · `use gameultra438`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra439

`import "std/c/gameultra439"` · `use gameultra439`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra440

`import "std/c/gameultra440"` · `use gameultra440`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra441

`import "std/c/gameultra441"` · `use gameultra441`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra442

`import "std/c/gameultra442"` · `use gameultra442`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra443

`import "std/c/gameultra443"` · `use gameultra443`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra444

`import "std/c/gameultra444"` · `use gameultra444`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra445

`import "std/c/gameultra445"` · `use gameultra445`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra446

`import "std/c/gameultra446"` · `use gameultra446`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra447

`import "std/c/gameultra447"` · `use gameultra447`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra448

`import "std/c/gameultra448"` · `use gameultra448`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra449

`import "std/c/gameultra449"` · `use gameultra449`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra450

`import "std/c/gameultra450"` · `use gameultra450`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra451

`import "std/c/gameultra451"` · `use gameultra451`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra452

`import "std/c/gameultra452"` · `use gameultra452`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra453

`import "std/c/gameultra453"` · `use gameultra453`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra454

`import "std/c/gameultra454"` · `use gameultra454`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra455

`import "std/c/gameultra455"` · `use gameultra455`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra456

`import "std/c/gameultra456"` · `use gameultra456`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra457

`import "std/c/gameultra457"` · `use gameultra457`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra458

`import "std/c/gameultra458"` · `use gameultra458`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra459

`import "std/c/gameultra459"` · `use gameultra459`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra460

`import "std/c/gameultra460"` · `use gameultra460`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra461

`import "std/c/gameultra461"` · `use gameultra461`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra462

`import "std/c/gameultra462"` · `use gameultra462`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra463

`import "std/c/gameultra463"` · `use gameultra463`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra464

`import "std/c/gameultra464"` · `use gameultra464`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra465

`import "std/c/gameultra465"` · `use gameultra465`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra466

`import "std/c/gameultra466"` · `use gameultra466`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra467

`import "std/c/gameultra467"` · `use gameultra467`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra468

`import "std/c/gameultra468"` · `use gameultra468`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra469

`import "std/c/gameultra469"` · `use gameultra469`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra470

`import "std/c/gameultra470"` · `use gameultra470`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra471

`import "std/c/gameultra471"` · `use gameultra471`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra472

`import "std/c/gameultra472"` · `use gameultra472`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra473

`import "std/c/gameultra473"` · `use gameultra473`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra474

`import "std/c/gameultra474"` · `use gameultra474`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra475

`import "std/c/gameultra475"` · `use gameultra475`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra476

`import "std/c/gameultra476"` · `use gameultra476`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra477

`import "std/c/gameultra477"` · `use gameultra477`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra478

`import "std/c/gameultra478"` · `use gameultra478`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra479

`import "std/c/gameultra479"` · `use gameultra479`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra480

`import "std/c/gameultra480"` · `use gameultra480`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra481

`import "std/c/gameultra481"` · `use gameultra481`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra482

`import "std/c/gameultra482"` · `use gameultra482`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra483

`import "std/c/gameultra483"` · `use gameultra483`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra484

`import "std/c/gameultra484"` · `use gameultra484`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra485

`import "std/c/gameultra485"` · `use gameultra485`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra486

`import "std/c/gameultra486"` · `use gameultra486`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra487

`import "std/c/gameultra487"` · `use gameultra487`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra488

`import "std/c/gameultra488"` · `use gameultra488`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra489

`import "std/c/gameultra489"` · `use gameultra489`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra490

`import "std/c/gameultra490"` · `use gameultra490`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra491

`import "std/c/gameultra491"` · `use gameultra491`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra492

`import "std/c/gameultra492"` · `use gameultra492`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra493

`import "std/c/gameultra493"` · `use gameultra493`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra494

`import "std/c/gameultra494"` · `use gameultra494`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra495

`import "std/c/gameultra495"` · `use gameultra495`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra496

`import "std/c/gameultra496"` · `use gameultra496`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra497

`import "std/c/gameultra497"` · `use gameultra497`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra498

`import "std/c/gameultra498"` · `use gameultra498`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra499

`import "std/c/gameultra499"` · `use gameultra499`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`

## std/c/gameultra500

`import "std/c/gameultra500"` · `use gameultra500`

- `astarGridPath(grid list number, w number, h number, sx number, sy number, gx number, gy number, blockedAbove number) → list number`
- `floodCount(grid list number, w number, h number, sx number, sy number, blockedAbove number) → number`
- `simplifyGridPath(path list number, w number) → list number`
