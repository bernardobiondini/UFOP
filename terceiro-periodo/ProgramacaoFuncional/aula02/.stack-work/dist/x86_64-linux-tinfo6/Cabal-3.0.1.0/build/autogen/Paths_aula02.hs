{-# LANGUAGE CPP #-}
{-# LANGUAGE NoRebindableSyntax #-}
{-# OPTIONS_GHC -fno-warn-missing-import-lists #-}
module Paths_aula02 (
    version,
    getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

#if defined(VERSION_base)

#if MIN_VERSION_base(4,0,0)
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#else
catchIO :: IO a -> (Exception.Exception -> IO a) -> IO a
#endif

#else
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#endif
catchIO = Exception.catch

version :: Version
version = Version [0,1,0,0] []
bindir, libdir, dynlibdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/home/be/Documentos/Programa-o-Funcional/aula02/.stack-work/install/x86_64-linux-tinfo6/f3dba253e0cfbcdafb9a19393b1245f513befc1ef9def32bd26aa62fa3bc828c/8.8.4/bin"
libdir     = "/home/be/Documentos/Programa-o-Funcional/aula02/.stack-work/install/x86_64-linux-tinfo6/f3dba253e0cfbcdafb9a19393b1245f513befc1ef9def32bd26aa62fa3bc828c/8.8.4/lib/x86_64-linux-ghc-8.8.4/aula02-0.1.0.0-IDIrInRNFopELObu11iXWy"
dynlibdir  = "/home/be/Documentos/Programa-o-Funcional/aula02/.stack-work/install/x86_64-linux-tinfo6/f3dba253e0cfbcdafb9a19393b1245f513befc1ef9def32bd26aa62fa3bc828c/8.8.4/lib/x86_64-linux-ghc-8.8.4"
datadir    = "/home/be/Documentos/Programa-o-Funcional/aula02/.stack-work/install/x86_64-linux-tinfo6/f3dba253e0cfbcdafb9a19393b1245f513befc1ef9def32bd26aa62fa3bc828c/8.8.4/share/x86_64-linux-ghc-8.8.4/aula02-0.1.0.0"
libexecdir = "/home/be/Documentos/Programa-o-Funcional/aula02/.stack-work/install/x86_64-linux-tinfo6/f3dba253e0cfbcdafb9a19393b1245f513befc1ef9def32bd26aa62fa3bc828c/8.8.4/libexec/x86_64-linux-ghc-8.8.4/aula02-0.1.0.0"
sysconfdir = "/home/be/Documentos/Programa-o-Funcional/aula02/.stack-work/install/x86_64-linux-tinfo6/f3dba253e0cfbcdafb9a19393b1245f513befc1ef9def32bd26aa62fa3bc828c/8.8.4/etc"

getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "aula02_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "aula02_libdir") (\_ -> return libdir)
getDynLibDir = catchIO (getEnv "aula02_dynlibdir") (\_ -> return dynlibdir)
getDataDir = catchIO (getEnv "aula02_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "aula02_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "aula02_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
